#ifndef CENEMY_H
#define CENEMY_H
//�L�����N�^�N���X�̃C���N���[�h
#include"CCharacter.h"
#include"CCollider.h"
#include"CPoint.h"
#include"CPlayer.h"
/*
�G�l�~�[�N���X
�L�����N�^�N���X���p��
*/
class CEnemy :public CCharacter{
public:
	int mFireCount;
	CCollider mSearch;
	CEnemy();
	static int mPointSize;//�|�C���g�̐�
	CPoint*mpPoint;//�ڎw���|�C���g
	int mPointCnt;//�|�C���^�̃J�E���^
	//�U���|�C���g
	static CPoint *mPoint;
	//�R���C�_
	CCollider mCollider;
	//�R���X�g���N�^
	//CEnemy(���f���A�ʒu�A��]�A�g�k)
	CEnemy(CModel*model, CVector position, CVector rotation, CVector scaie);
	//�X�V����
	void Update();
	//�폜�\��
	void Collision(CCollider*m, CCollider*y);
};
#endif