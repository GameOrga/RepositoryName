#include "CGate.h"
int CGate::CG = 1;
CGate::CGate(CModel*model, CVector position, CVector rotation, CVector scale)
:mGateB(this, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f, 1.0f, 1.0f), 4.0f){

	//モデル、位置、回転、拡縮
	mpModel = model;

	mPosition = position;

	mRotation = rotation;

	mScale = scale;

}

//衝突判定
void CGate::Collision(CCollider*im, CCollider*y){

	if (CCollider::Collision(im, y)){

		switch (y->mpParent->mTag)
		{
		
		case EPLAYER:
		//衝突しているなら無効+カウントを1減らす
			CG--;

		//ItemCount+1;
		mEnabled = false;

		default:
			break;
		}
		
	}

}
