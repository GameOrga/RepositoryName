//プレイヤークラスのインクルード
#include"CPlayer.h"
//キー入力クラスのインクルード
#include"CKey.h"
#include"CBullet.h"
#include"CTaskManager.h"
#include"CSceneGame.h"
#include"CEnemy.h"
CPlayer *CPlayer::mPlayer = 0;
extern std::shared_ptr<CTexture>TextureExp;
//CPlayer*CEnemy::mPlayer;
//更新処理
CPlayer::CPlayer()
:mCollider(this, CVector(0.0f, -30.0f, -5.0f), CVector(0.0f,0.0f,0.0f),
CVector(5.0f, 5.0f, 5.0f), 0.8f), FireCount(0), mVelovcityJump(0)
{
	mTag = EPLAYER;//キャラクター種類はプレイヤー
	mCollider.mTag = CCollider::EBODY;//コライダ種類は機体
	//線分コライダの設定
	//前後
	mLine[0].SetLine(this, CVector(0.0f, 0.0f, -14.0f), CVector(0.0f, 0.0f, 17.0f));
	//上下
	mLine[1].SetLine(this, CVector(0.0f, 9.0f, -8.0f), CVector(0.0f, -9.0f, -8.0f));

	mLine[2].SetLine(this, CVector(0.0f, 0.0f, -8.0f), CVector(9.0f, 0.0f, -8.0f));

	mLine[3].SetLine(this, CVector(0.0f, 0.0f, -8.0f), CVector(-9.0f, 0.0f, -8.0f));

	mPlayer = this;

	int Priority = 10;
}

void CPlayer::Update(){
	//Aキー入力で回転
	if (CKey::Push('A')){
		//Y軸で回転値を増加
		mRotation.mY += 5;
		if (CKey::Push('L')){
			mRotation.mY -= 4;
		}
	}
	//Aキー入力で回転
	if (CKey::Push('D')){
		//Y軸で回転値を増加
		mRotation.mY -= 5;
		if (CKey::Push('L')){
			mRotation.mY += 4;
		}
	}

	//キー入力で前進
	if (CKey::Push('W')){
		//Z軸方向に1進んだ値を回転させる
		mPosition = CVector(0.0f, 0.0f, 1.5f)*mMatrix;
		if (CKey::Push('B')){
			if (Dash < 100 && cool <= 0){
				mPosition = CVector(0.0f, 0.0f, 5.0f)*mMatrix;
				Dash++;
			}
		}
		else if (Dash > 0 && cool <= 0){
			Dash--;
		}
	}
	if (CKey::Push('S')){
		//Z軸方向に1進んだ値を回転させる
		mPosition = CVector(0.0f, 0.0f, -1.5f)*mMatrix;
		if (CKey::Push('B')){
			if (Dash < 100 && cool <= 0){
				mPosition = CVector(0.0f, 0.0f, -5.0f)*mMatrix;
				Dash++;
			}
		}
		else if (Dash > 0&&cool<=0){
			Dash--;
		}
	}
	if (Dash > 98&&cool<=0){
		cool = 200;
	}
	if (cool >= 0){
		cool--;
		if (Dash >= 0){
			Dash--;
		}
	}
	//if (CKey::Once('K')){
	//	mVelovcityJump = JUMPV0;
	//}
	//mVelovcityJump = mVelovcityJump - G;
	//mPosition.mY = mPosition.mY + mVelovcityJump;
	////Sキー入力で上向き
	//if (CKey::Push('S')){
	//	//X軸の回転値を減算
	//	mRotation.mX -= 1;
	//}
	////Wキー入力で上向き
	//if (CKey::Push('W')){
	//	//X軸のの回転値を加算
	//	mRotation.mX += 1;
	//}
	//CCharacterの更新
	CCharacter::Update();
	//if (FireCount > 0) {
	//	FireCount--;
	//}
	////スペースキー入力で弾発射
	//else if (CKey::Push(VK_SPACE)){
	//	CBullet*bullet = new CBullet();
	//	bullet->Set(0.1f, 1.5f);
	//	bullet->mPosition = CVector(0.0f, 0.0f, 10.0f)*mMatrix;
	//	bullet->mRotation = mRotation;
	//	FireCount = 20;
	//	//TaskManager.Add(bullet);
	//}
}
void CPlayer::Collision(CCollider*mc, CCollider*yc){
	if (mc->mType == CCollider::ESPHERE&&yc->mType == CCollider::ESPHERE){
		if (yc->mTag == CCollider::EBODY){
			if (CCollider::Collision(mc, yc)){
			}
		}
	}
	else{
		//自分のコライダタイプの判定
		switch (mc->mType){
		case CCollider::ELINE://線分コライダ
			//相手コライダが三角コライダの時
			if (yc->mType == CCollider::ETRIANGLE){
				CVector adjust;//調整用ベクトル
				//三角形と線分の衝突判定
				if (CCollider::CollisionTriangleLine(yc, mc, &adjust)){
					//位置の更新
					mPosition = mPosition - adjust*-1;
					//行列の更新
					mVelovcityJump = 0;
					CCharacter::Update();
				}
			}
		}
	}
}

