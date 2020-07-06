#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H
//タスクマネージャのインクルード
#include"CTaskManager.h"
/*
コリジョンマネージャ
コライダのリスト管理
*/
class CCollisionManager :public CTaskManager{
public:
	//衝突判定
	void Collision();
};
//他で使えるように外部参照する
extern CCollisionManager CollisionManager;
#endif
