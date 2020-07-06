#ifndef CCHARACTER_H
#define CCHARACTER_H
//ベクトルクラスのインクルード
#include"CVector.h"
//モデルクラスのインクルード
#include"CModel.h"
//マトリクスクラスのインクルード
#include"CMatrix.h"
#include"CTask.h"
//コライダクラスの宣言
/*
キャラクタークラス
ゲームキャラクターの基本的な機能を定義する
*/
class CCollider;
class CCharacter:public CTask{
public:
	CVector mPosition;//位置
	CVector mRotation;//回転
	CVector mScale;//拡大縮小
	CModel *mpModel;//モデルのポインタ
	CMatrix mMatrix;//合成行列
	CMatrix mMatrixTranslate;//平行移動行列
	CMatrix mMartixRotate;//回転行列
	CMatrix mMatrixScale;//拡大縮小行列
	~CCharacter();
	CCharacter();
	//更新処理
	void Update();
	//描画処理
	void Render();
	//衝突判定
	virtual void Collision(CCollider*mycol, CCollider*youcol){}
	enum ETag{
		ENONE,//初期値
		EPOINT,//ポイント
		EPLAYER,//プレイヤー
		EAIRBASE,//空軍基地
		EOBJECT,//木
		EENEMYSTOP,//妨害アイテム
	};
	ETag mTag;

	int Priority;

};
#endif