#ifndef CENEMY_H
#define CENEMY_H
//キャラクタクラスのインクルード
#include"CCharacter.h"
#include"CCollider.h"
#include"CPoint.h"
#include"CPlayer.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CEnemy :public CCharacter{
public:
	int mFireCount;
	CCollider mSearch;
	CEnemy();
	static int mPointSize;//ポイントの数
	CPoint*mpPoint;//目指すポイント
	int mPointCnt;//ポインタのカウンタ
	//誘導ポイント
	static CPoint *mPoint;
	//コライダ
	CCollider mCollider;
	//コンストラクタ
	//CEnemy(モデル、位置、回転、拡縮)
	CEnemy(CModel*model, CVector position, CVector rotation, CVector scaie);
	//更新処理
	void Update();
	//削除予定
	void Collision(CCollider*m, CCollider*y);
};
#endif