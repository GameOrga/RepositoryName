#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//キャラクタクラスのインクルード
#include"CCharacter.h"
//トランスフォームクラスのインクルード
#include"CTransform.h"

/*
コライダクラス
衝突判定データ
*/
//衝突判定
//Collision
//retrun:true(衝突している)false(衝突していない)
class CCollider :public CTransform,public CTask{
public:
	//コライダの種類
	enum ETag{
		ENONE,
		EBODY,//機体
		ESEARCH,//サーチ
		EITEM,
		EOBJECT,//障害物
	};
	ETag mTag;
	enum EType{
		ESPHERE,//球コライダ
		ETRIANGLE,//三角コライダ
		ELINE,//線分コライダ
	};
	EType mType;//コライダタイプ
	//頂点
	CVector mV[3];
	//デフォルトコンストラクタ
	CCollider();
	//コンストラクタ
	//CCollider(親、頂点1、頂点2)
	CCollider(CCharacter*parent, const CVector&v0, const CVector&v1);
	//線分コライダの設定
	//SetLine(親、頂点1、頂点2)
	void SetLine(CCharacter*parent, const CVector&v0, const CVector&v1);
	//CCollider(親、頂点1、頂点2、頂点3)
	CCollider(CCharacter*parent, const CVector&v0, const CVector&v1, const CVector&v2);
	//三角コライダの設定
	//SetTriangle(親、頂点1、頂点2、頂点3)
	void SetTriangle(CCharacter*parent, const CVector&v0, const CVector&v1, const CVector&v2);
	CCharacter*mpParent;//親
	float mRadius;//半径
	//コンストラクタ
	//CCollider(親、位置、回転、拡縮、半径)
	CCollider(CCharacter*parent, CVector position, CVector rotation, CVector scale, float radius);
	//描画
	void Render();
	~CCollider();
	static bool Collision(CCollider*m, CCollider*y);
	//CollisionTriangleLine(三角コライダ、線分コライダ、調整値)
	//return:true(衝突している)false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionTriangleLine(CCollider*triangle, CCollider*line, CVector*adjust);
};

#endif