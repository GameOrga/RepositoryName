#include"CObj.h"
//コンストラクタ
//model:モデルのポインタ posision 位置 rotattion 回転 scale 拡張
CObj::CObj(CModel*model, const CVector&position, const
	CVector&rotation, const CVector&scale)
	:mpCollider(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//モデルの三角形の数分、コライダの配列を作成します
	mpCollider = new CCollider[model->mTriangle.size()];
	for (int i = 0; i < model->mTriangle.size(); i++){
		//コライダを三角形コライダで設定していきます
		mpCollider[i].SetTriangle(this,
			model->mTriangle[i].mV[0],
			model->mTriangle[i].mV[1],
			model->mTriangle[i].mV[2]);

	}
}

//デストラクタ
CObj::~CObj(){
	//コライダがあれば削除
	if (mpCollider){
		//delete[]配列を削除
		delete[] mpCollider;
	}
}