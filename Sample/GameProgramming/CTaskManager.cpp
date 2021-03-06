#include"CTaskManager.h"
CTaskManager TaskManager;
CTaskManager::CTaskManager()
: mpHead(0), mpTail(0)
{}

CTaskManager::~CTaskManager(){
}
//リストに追加
//Add(タスクポインタ)
void CTaskManager::Add(CTask*task){
	//リストが空(先頭が0)
	if (mpHead == 0){
		//リストの先頭にする
		mpHead = task;
		task->mpPrev = 0;
		//リストの最後にする
		mpTail = task;
		task->mpNext = 0;
	}
	else{
		//リストの先頭にする
		task->mpNext = mpHead;
		mpHead->mpPrev = task;
		mpHead = task;
		mpHead->mpPrev = 0;
	}
}

void CTaskManager::Changepriority(CTask*task, int priority){

	Remove(task);
	task->mPriority = priority;
	Add(task);
}

//更新
void CTaskManager::Update(){
	//先頭から最後まで繰り返し
	CTask*pos = mpHead;
	while (pos){
		//更新処理を呼ぶ
		pos->Update();
		//次へ
		pos = pos->mpNext;
	}
}

//描画
void CTaskManager::Render(){
	//先頭から最後まで繰り返し
	CTask*pos = mpHead;
	while (pos){
		//描画処理を呼ぶ
		pos->Render();
		//次へ
		pos = pos->mpNext;
	}
}
//リストから削除
//Rwmove(タスクのポインタ)
void CTaskManager::Remove(CTask*task){
	//taskが先頭の時
	if (task->mpPrev == 0){
		mpHead = task->mpNext;
	}
	else{
		task->mpPrev->mpNext = task->mpNext;
	}
	//taskが最後の時
	if (task->mpNext == 0){
		mpTail = task->mpPrev;
	}
	else{
		task->mpNext->mpPrev = task->mpPrev;
	}
}
//タスクの削除
void CTaskManager::Delete(){
	//先頭から最後まで繰り返し
	CTask*pos = mpHead;
	while (pos){
		CTask*del = pos;
		//次へ
		pos = pos->mpNext;
		//mEnabledがfalseなら削除
		if (del->mEnabled == false){
			delete del;
		}
	}
}