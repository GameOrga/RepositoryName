#ifndef CPOINT_H
#define CPOINT_H
#include"CCollider.h"
#include"CCharacter.h"

/*
�|�C���g�N���X
�G�@�Ȃǂ�ڕW�ɂ���
*/
class CPoint :public CCharacter{
public:
	CCollider mCollider;//�R���C�_�ǉ�
	CPoint();
	//�ݒ�
	//Set(�ʒu�A���a)
	void Set(const CVector&pos, float r);
};
#endif