#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include"CCharacter.h"
//�g�����X�t�H�[���N���X�̃C���N���[�h
#include"CTransform.h"

/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
//�Փ˔���
//Collision
//retrun:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
class CCollider :public CTransform,public CTask{
public:
	//�R���C�_�̎��
	enum ETag{
		ENONE,
		EBODY,//�@��
		ESEARCH,//�T�[�`
		EITEM,
		EOBJECT,//��Q��
	};
	ETag mTag;
	enum EType{
		ESPHERE,//���R���C�_
		ETRIANGLE,//�O�p�R���C�_
		ELINE,//�����R���C�_
	};
	EType mType;//�R���C�_�^�C�v
	//���_
	CVector mV[3];
	//�f�t�H���g�R���X�g���N�^
	CCollider();
	//�R���X�g���N�^
	//CCollider(�e�A���_1�A���_2)
	CCollider(CCharacter*parent, const CVector&v0, const CVector&v1);
	//�����R���C�_�̐ݒ�
	//SetLine(�e�A���_1�A���_2)
	void SetLine(CCharacter*parent, const CVector&v0, const CVector&v1);
	//CCollider(�e�A���_1�A���_2�A���_3)
	CCollider(CCharacter*parent, const CVector&v0, const CVector&v1, const CVector&v2);
	//�O�p�R���C�_�̐ݒ�
	//SetTriangle(�e�A���_1�A���_2�A���_3)
	void SetTriangle(CCharacter*parent, const CVector&v0, const CVector&v1, const CVector&v2);
	CCharacter*mpParent;//�e
	float mRadius;//���a
	//�R���X�g���N�^
	//CCollider(�e�A�ʒu�A��]�A�g�k�A���a)
	CCollider(CCharacter*parent, CVector position, CVector rotation, CVector scale, float radius);
	//�`��
	void Render();
	~CCollider();
	static bool Collision(CCollider*m, CCollider*y);
	//CollisionTriangleLine(�O�p�R���C�_�A�����R���C�_�A�����l)
	//return:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
	//�����l:�Փ˂��Ȃ��ʒu�܂Ŗ߂��l
	static bool CollisionTriangleLine(CCollider*triangle, CCollider*line, CVector*adjust);
};

#endif