#include "CItem.h"
int CItem::ItemCount = 0;//(/ω＼)
int CItem::GateCount = 0;
CItem::CItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, CVector(0.0f, 1.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f, 1.0f, 1.0f), 4.0f){
	mCollider.mTag = CCollider::EITEM;
	//モデル、位置、回転、拡縮
	mpModel = model;

	mPosition = position;

	mRotation = rotation;

	mScale = scale;

}

//衝突判定
void CItem::Collision(CCollider*im, CCollider*y){
	if (im->mType == CCollider::ESPHERE&&y->mType == CCollider::ESPHERE){

		if (CCollider::Collision(im, y)){

			//衝突しているなら無効+カウントを1減らす
			if (y->mTag == CCollider::EBODY){
				//衝突したコライダの親の種類を判定
				switch (y->mpParent->mTag){
				case EPLAYER:

					ItemCount++;

					GateCount++;
					//位置の更新

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

	//モデル、位置、回転、拡縮
	mpModel = model;

	mPosition = position;

	mRotation = rotation;

	mScale = scale;

}

//衝突判定
void CDisturdanceItem::Collision(CCollider*Dm, CCollider*y){
	if (Dm->mTag == CCollider::ESPHERE&&y->mType == CCollider::ESPHERE){

		if (CCollider::Collision(Dm, y)){

			//衝突しているなら無効+カウントを1減らす
			if (y->mTag == CCollider::EBODY){
				//衝突したコライダの親の種類を判定
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

	//モデル、位置、回転、拡縮
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

//モデル、位置、回転、拡縮
mpModel = model;

mPosition = position;

mRotation = rotation;

mScale = scale;

}

