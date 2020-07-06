#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H
//タスククラスのインクルード
#include"CTask.h"
/*
タスクマネージャー
タスクリストの管理
*/
class CTaskManager{
public:
	CTask*mpHead;//先頭ポインタ
	CTask*mpTail;//最後ポインタ
	//デフォルトコンストラクタ
	CTaskManager();
	//デストラクタ
	virtual~CTaskManager();
	//	リストに追加
	//Add(タスクのポインタ)
	void Add(CTask*task);
	//更新
	void Update();
	//描画
	void Render();
	//リストから削除
	//Remove(タスクのポインタ)
	void Remove(CTask*task);
	//タスクの削除
	void Delete();
	//優先度変更
	void Changepriority(CTask*task, int priority);

};
//タスクマネージャyの外部参照
extern CTaskManager TaskManager;
#endif