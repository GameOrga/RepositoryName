#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include"CCharacter.h"
#include"CPlayer.h"
#include"CMap.h"
/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:
	static int EnemyHP;
	//2D描画スタート
	//Start2D(左座標、右座標、下座標、上座標)
	void Start2D(float left, float right, float bottom, float top);
	//2D描画終了
	void End2D();
	CMap mMap;//マップのインスタンス
	CCharacter Character;
	CPlayer Player;
	CModel mItem;
	CModel mGate;
	CModel mWood;
	CModel mFallenTree;
	CModel mCube;
	CModel mStop;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	CSceneGame()
		: mMap(-1){}
	~CSceneGame();
};

#endif
