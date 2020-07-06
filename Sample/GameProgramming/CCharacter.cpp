#include"CCharacter.h"
#include"CTaskManager.h"
CCharacter::CCharacter()
:mpModel(0), mTag(ENONE)
{
	//タスクリストに追加
	TaskManager.Add(this);
}
//更新処理
void CCharacter::Update(){
	//拡大縮小行列の設定
	mMatrixScale.Scale(mScale.mX, mScale.mY, mScale.mZ);
	//回転行列の設定
	mMartixRotate =
		CMatrix().RotateZ(mRotation.mZ)*
		CMatrix().RotateX(mRotation.mX)*
		CMatrix().RotateY(mRotation.mY);
	//平行移動行列の設定
	mMatrixTranslate.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
	//合成行列の設定
	mMatrix = mMatrixScale*mMartixRotate*mMatrixTranslate;
}
//描画処理
void CCharacter::Render(){
	//mpModelが0以外なら描画
	if (mpModel){
		//モデルの描画
		mpModel->Render(mMatrix);
	}
}
CCharacter::~CCharacter(){
	//タスクリストからの削除
	TaskManager.Remove(this);
}