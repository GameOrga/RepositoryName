//�v���C���[�N���X�̃C���N���[�h
#include"CPlayer.h"
//�L�[���̓N���X�̃C���N���[�h
#include"CKey.h"
#include"CBullet.h"
#include"CTaskManager.h"
#include"CSceneGame.h"
#include"CEnemy.h"
CPlayer *CPlayer::mPlayer = 0;
extern std::shared_ptr<CTexture>TextureExp;
//CPlayer*CEnemy::mPlayer;
//�X�V����
CPlayer::CPlayer()
:mCollider(this, CVector(0.0f, -30.0f, -5.0f), CVector(0.0f,0.0f,0.0f),
CVector(5.0f, 5.0f, 5.0f), 0.8f), FireCount(0), mVelovcityJump(0)
{
	mTag = EPLAYER;//�L�����N�^�[��ނ̓v���C���[
	mCollider.mTag = CCollider::EBODY;//�R���C�_��ނ͋@��
	//�����R���C�_�̐ݒ�
	//�O��
	mLine[0].SetLine(this, CVector(0.0f, 0.0f, -14.0f), CVector(0.0f, 0.0f, 17.0f));
	//�㉺
	mLine[1].SetLine(this, CVector(0.0f, 9.0f, -8.0f), CVector(0.0f, -9.0f, -8.0f));

	mLine[2].SetLine(this, CVector(0.0f, 0.0f, -8.0f), CVector(9.0f, 0.0f, -8.0f));

	mLine[3].SetLine(this, CVector(0.0f, 0.0f, -8.0f), CVector(-9.0f, 0.0f, -8.0f));

	mPlayer = this;

	int Priority = 10;
}

void CPlayer::Update(){
	//A�L�[���͂ŉ�]
	if (CKey::Push('A')){
		//Y���ŉ�]�l�𑝉�
		mRotation.mY += 5;
		if (CKey::Push('L')){
			mRotation.mY -= 4;
		}
	}
	//A�L�[���͂ŉ�]
	if (CKey::Push('D')){
		//Y���ŉ�]�l�𑝉�
		mRotation.mY -= 5;
		if (CKey::Push('L')){
			mRotation.mY += 4;
		}
	}

	//�L�[���͂őO�i
	if (CKey::Push('W')){
		//Z��������1�i�񂾒l����]������
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
		//Z��������1�i�񂾒l����]������
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
	////S�L�[���͂ŏ����
	//if (CKey::Push('S')){
	//	//X���̉�]�l�����Z
	//	mRotation.mX -= 1;
	//}
	////W�L�[���͂ŏ����
	//if (CKey::Push('W')){
	//	//X���̂̉�]�l�����Z
	//	mRotation.mX += 1;
	//}
	//CCharacter�̍X�V
	CCharacter::Update();
	//if (FireCount > 0) {
	//	FireCount--;
	//}
	////�X�y�[�X�L�[���͂Œe����
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
		//�����̃R���C�_�^�C�v�̔���
		switch (mc->mType){
		case CCollider::ELINE://�����R���C�_
			//����R���C�_���O�p�R���C�_�̎�
			if (yc->mType == CCollider::ETRIANGLE){
				CVector adjust;//�����p�x�N�g��
				//�O�p�`�Ɛ����̏Փ˔���
				if (CCollider::CollisionTriangleLine(yc, mc, &adjust)){
					//�ʒu�̍X�V
					mPosition = mPosition - adjust*-1;
					//�s��̍X�V
					mVelovcityJump = 0;
					CCharacter::Update();
				}
			}
		}
	}
}

