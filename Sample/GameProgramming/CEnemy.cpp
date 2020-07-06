#include"CEnemy.h" 
#include"CCollisionManager.h"
#include"CEffect.h"
#include"CBullet.h"
#include"CItem.h"
#include"CSceneGame.h"
int CSceneGame::EnemyHP;
CPoint *CEnemy::mPoint;
//CPlayer *CEnemy::mPlayer;
//�X�}�[�g�|�C���^�̐���
extern std::shared_ptr<CTexture>TextureExp;
int CEnemy::mPointSize = 0;
//�R���X�g���N�^
//CEnemy(���f���A�ʒu�A��]�A�g�k)
CEnemy::CEnemy(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f/scale.mX,1.0f/scale.mY,1.0f/scale.mZ),0.8f)
//, mSearch(this, CVector(0.0f, 0.0f, 60.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ),10.0f)
, mFireCount(1)
{
	mCollider.mTag = CCollider::EBODY;
	mSearch.mTag = CCollider::ESEARCH;
	mPointCnt = 0;//�ŏ��̃|�C���g��ݒ�
	mpPoint = &mPoint[mPointCnt];//&mPoint[mPointCnt];//�ڎw���|�C���g�̃|�C���^��ݒ�
	//���f���A�ʒu�A��]�A�g����ݒ肷��
	mpModel = model;//���f���̐ݒ�
	mPosition = position;//�ʒu�̐ݒ�
	mRotation = rotation;//��]�̐ݒ�
	mScale = scale;//�g�k�̐ݒ�
}

//�X�V����
void CEnemy::Update(){
	CVector dir = CPlayer::mPlayer->mPosition - mPosition;
	//�������̃x�N�g�������߂�
	CVector left = CVector(1.0f, 0.0f, 0.0f)*
		CMatrix().RotateY(mRotation.mY);
	//������̃x�N�g�������߂�
	CVector up = CVector(0.0f, 1.0f, 0.0f)*
		CMatrix().RotateX(mRotation.mX)*
		CMatrix().RotateY(mRotation.mY);
	//���E�̉�]����
	if (left.Dot(dir) > 0.0f){
		mRotation.mY += 2.5f;
	}
	else if (left.Dot(dir) < 0.0f){
		mRotation.mY -= 2.5f;
	}
	////�㉺�̉�]����
	//if (up.Dot(dir)>0.0f){
	//	mRotation.mX -= 0.3f;
	//}
	//else if (up.Dot(dir) < 0.0f){
	//	mRotation.mX += 0.3f;
	//}
	//�s����ړ�
	CCharacter::Update();
	//�ʒu���ړ�
	mPosition = CVector(0.0f, 0.0f, 0.053f+CItem::ItemCount*0.009)*mMatrix;
	//��]������
	//mRotation.mY += 0.5f;
}

void CEnemy::Collision(CCollider*m, CCollider*y){
	//���ɋ��R���C�_�̎�
	if (m->mType == CCollider::ESPHERE
		&& y->mType == CCollider::ESPHERE){
		//�R���C�_���Փ˂��Ă���
		if (CCollider::Collision(m, y)){
			//�R���C�_���T�[�`������
			if (m->mTag == CCollider::ESEARCH){
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
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
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
				switch (y->mpParent->mTag){
				case EPOINT://�|�C���g�̎�
					//�Փ˂����|�C���^�Ɩڎw���Ă���|�C���^��������
					if (y->mpParent == mpPoint){
						mPointCnt++;//���̃|�C���g�ɂ���
						//�Ōゾ������ŏ��ɂ���
						mPointCnt %= mPointSize;
						//���̃|�C���g�̃|�C���^��ݒ�
						mpPoint = &mPoint[mPointCnt];
					}
					break;
				//default:
					////�G�t�F�N�g����
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
