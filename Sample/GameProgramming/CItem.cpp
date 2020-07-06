#include "CItem.h"
int CItem::ItemCount = 0;//(/�ց_)
int CItem::GateCount = 0;
CItem::CItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f, 1.0f, 1.0f), 4.0f){
	mCollider.mTag = CCollider::EITEM;
	//���f���A�ʒu�A��]�A�g�k
	mpModel = model;

	mPosition = position;

	mRotation = rotation;

	mScale = scale;

}

//�Փ˔���
void CItem::Collision(CCollider*im, CCollider*y){
	if (im->mType == CCollider::ESPHERE&&y->mType == CCollider::ESPHERE){

		if (CCollider::Collision(im, y)){

			//�Փ˂��Ă���Ȃ疳��+�J�E���g��1���炷
			if (y->mTag == CCollider::EBODY){
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
				switch (y->mpParent->mTag){
				case EPLAYER:

					ItemCount++;

					GateCount++;
					//�ʒu�̍X�V

					mEnabled = false;


				}
			}
		}
	}
}

CDisturdanceItem::CDisturdanceItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f, 1.0f, 1.0f), 6.0f){

	mCollider.mTag = CCollider::EITEM;

	//���f���A�ʒu�A��]�A�g�k
	mpModel = model;

	mPosition = position;

	mRotation = rotation;

	mScale = scale;

}

//�Փ˔���
void CDisturdanceItem::Collision(CCollider*Dm, CCollider*y){
	if (Dm->mTag == CCollider::ESPHERE&&y->mType == CCollider::ESPHERE){

		if (CCollider::Collision(Dm, y)){

			//�Փ˂��Ă���Ȃ疳��+�J�E���g��1���炷
			if (y->mTag == CCollider::EBODY){
				//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
				switch (y->mpParent->mTag){
				case EPLAYER:

					mEnabled = false;

				}
			}
		}
	}
}

CWood::CWood(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f, 1.0f, 1.0f), 4.0f){

	mCollider.mTag = CCollider::EOBJECT;

	mTag = CCharacter::EOBJECT;

	//���f���A�ʒu�A��]�A�g�k
	mpModel = model;

	mPosition = position;

	mRotation = rotation;

	mScale = scale;

}

CFallenTree::CFallenTree(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f, 1.0f, 1.0f), 0.0f){

mCollider.mTag = CCollider::EOBJECT;

mTag = CCharacter::EOBJECT;

//���f���A�ʒu�A��]�A�g�k
mpModel = model;

mPosition = position;

mRotation = rotation;

mScale = scale;

}

