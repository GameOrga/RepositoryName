#include "CGate.h"
int CGate::CG = 1;
CGate::CGate(CModel*model, CVector position, CVector rotation, CVector scale)
:mGateB(this, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f, 1.0f, 1.0f), 4.0f){

	//���f���A�ʒu�A��]�A�g�k
	mpModel = model;

	mPosition = position;

	mRotation = rotation;

	mScale = scale;

}

//�Փ˔���
void CGate::Collision(CCollider*im, CCollider*y){

	if (CCollider::Collision(im, y)){

		switch (y->mpParent->mTag)
		{
		
		case EPLAYER:
		//�Փ˂��Ă���Ȃ疳��+�J�E���g��1���炷
			CG--;

		//ItemCount+1;
		mEnabled = false;

		default:
			break;
		}
		
	}

}
