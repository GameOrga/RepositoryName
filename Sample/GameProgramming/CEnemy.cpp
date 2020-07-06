#include"CEnemy.h" 
#include"CCollisionManager.h"
#include"CEffect.h"
#include"CBullet.h"
#include"CItem.h"
#include"CSceneGame.h"
int CSceneGame::EnemyHP;
CPoint *CEnemy::mPoint;
//CPlayer *CEnemy::mPlayer;
//スマートポインタの生成
extern std::shared_ptr<CTexture>TextureExp;
int CEnemy::mPointSize = 0;
//コンストラクタ
//CEnemy(モデル、位置、回転、拡縮)
CEnemy::CEnemy(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f/scale.mX,1.0f/scale.mY,1.0f/scale.mZ),0.8f)
//, mSearch(this, CVector(0.0f, 0.0f, 60.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ),10.0f)
, mFireCount(1)
{
	mCollider.mTag = CCollider::EBODY;
	mSearch.mTag = CCollider::ESEARCH;
	mPointCnt = 0;//最初のポイントを設定
	mpPoint = &mPoint[mPointCnt];//&mPoint[mPointCnt];//目指すポイントのポインタを設定
	//モデル、位置、回転、拡張を設定する
	mpModel = model;//モデルの設定
	mPosition = position;//位置の設定
	mRotation = rotation;//回転の設定
	mScale = scale;//拡縮の設定
}

//更新処理
void CEnemy::Update(){
	CVector dir = CPlayer::mPlayer->mPosition - mPosition;
	//左方向のベクトルを求める
	CVector left = CVector(1.0f, 0.0f, 0.0f)*
		CMatrix().RotateY(mRotation.mY);
	//上方向のベクトルを求める
	CVector up = CVector(0.0f, 1.0f, 0.0f)*
		CMatrix().RotateX(mRotation.mX)*
		CMatrix().RotateY(mRotation.mY);
	//左右の回転処理
	if (left.Dot(dir) > 0.0f){
		mRotation.mY += 2.5f;
	}
	else if (left.Dot(dir) < 0.0f){
		mRotation.mY -= 2.5f;
	}
	////上下の回転処理
	//if (up.Dot(dir)>0.0f){
	//	mRotation.mX -= 0.3f;
	//}
	//else if (up.Dot(dir) < 0.0f){
	//	mRotation.mX += 0.3f;
	//}
	//行列を移動
	CCharacter::Update();
	//位置を移動
	mPosition = CVector(0.0f, 0.0f, 0.053f+CItem::ItemCount*0.009)*mMatrix;
	//回転させる
	//mRotation.mY += 0.5f;
}

void CEnemy::Collision(CCollider*m, CCollider*y){
	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE
		&& y->mType == CCollider::ESPHERE){
		//コライダが衝突している
		if (CCollider::Collision(m, y)){
			//コライダがサーチが判定
			if (m->mTag == CCollider::ESEARCH){
				//衝突したコライダの親の種類を判定
				switch (y->mpParent->mTag){
				case EPLAYER:
				case EAIRBASE:
					if (mFireCount > 0) {
						mFireCount--;
					}
					else{
						CBullet*bullet = new CBullet();
						bullet->Set(0.1f, 1.5f);
						bullet->mPosition = CVector(0.0f, 0.0f, 10.0f)*mMatrix;
						bullet->mRotation = mRotation;
						mFireCount = 60;
						break;
					}
				}
			}
			else{
				//衝突したコライダの親の種類を判定
				switch (y->mpParent->mTag){
				case EPOINT://ポイントの時
					//衝突したポインタと目指しているポインタが同じ時
					if (y->mpParent == mpPoint){
						mPointCnt++;//次のポイントにする
						//最後だったら最初にする
						mPointCnt %= mPointSize;
						//次のポイントのポインタを設定
						mpPoint = &mPoint[mPointCnt];
					}
					break;
				//default:
					////エフェクト生成
					//new CEffect(mPosition, 1.0f, 1.0f, TextureExp, 4, 4, 1);
					//CSceneGame::EnemyHP--;
					//if (CSceneGame::EnemyHP < 0){
					//	mEnabled = false;
					//}
				}
			}
		}
	}
}
