#include"CTaskManager.h"
CTaskManager TaskManager;
CTaskManager::CTaskManager()
: mpHead(0), mpTail(0)
{}

CTaskManager::~CTaskManager(){
}
//���X�g�ɒǉ�
//Add(�^�X�N�|�C���^)
void CTaskManager::Add(CTask*task){
	//���X�g����(�擪��0)
	if (mpHead == 0){
		//���X�g�̐擪�ɂ���
		mpHead = task;
		task->mpPrev = 0;
		//���X�g�̍Ō�ɂ���
		mpTail = task;
		task->mpNext = 0;
	}
	else{
		//���X�g�̐擪�ɂ���
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

//�X�V
void CTaskManager::Update(){
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask*pos = mpHead;
	while (pos){
		//�X�V�������Ă�
		pos->Update();
		//����
		pos = pos->mpNext;
	}
}

//�`��
void CTaskManager::Render(){
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask*pos = mpHead;
	while (pos){
		//�`�揈�����Ă�
		pos->Render();
		//����
		pos = pos->mpNext;
	}
}
//���X�g����폜
//Rwmove(�^�X�N�̃|�C���^)
void CTaskManager::Remove(CTask*task){
	//task���擪�̎�
	if (task->mpPrev == 0){
		mpHead = task->mpNext;
	}
	else{
		task->mpPrev->mpNext = task->mpNext;
	}
	//task���Ō�̎�
	if (task->mpNext == 0){
		mpTail = task->mpPrev;
	}
	else{
		task->mpNext->mpPrev = task->mpPrev;
	}
}
//�^�X�N�̍폜
void CTaskManager::Delete(){
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask*pos = mpHead;
	while (pos){
		CTask*del = pos;
		//����
		pos = pos->mpNext;
		//mEnabled��false�Ȃ�폜
		if (del->mEnabled == false){
			delete del;
		}
	}
}