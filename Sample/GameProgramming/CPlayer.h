#ifndef CPLAYER_H
#define CPLAYER_H
//#define G (1.0f/60.0f)
//#define JUMPV0 (0.4f)
//キャラクタクラスのインクルード
#include"CCharacter.h"
#include"CCollider.h"
#include"CEffect.h"
/*
プレイヤークラスのインクルード
#include"CCharacter.h
*/


class CPlayer:public CCharacter{
public:
	CPlayer*mpPoint;//目指すポイント
	float mVelovcityJump;
	int cool = 0;
	int Dash=0;
	int FireCount;
	static CPlayer*mPlayer;
	//衝突判定
	void Collision(CCollider*mc, CCollider*yc);
	CPlayer();
	//コライダ
	CCollider mCollider;
	CCollider mLine[4];//線分コライダ
	//更新処理
	void Update();
};
#endif