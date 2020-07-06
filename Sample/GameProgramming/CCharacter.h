#ifndef CCHARACTER_H
#define CCHARACTER_H
//�x�N�g���N���X�̃C���N���[�h
#include"CVector.h"
//���f���N���X�̃C���N���[�h
#include"CModel.h"
//�}�g���N�X�N���X�̃C���N���[�h
#include"CMatrix.h"
#include"CTask.h"
//�R���C�_�N���X�̐錾
/*
�L�����N�^�[�N���X
�Q�[���L�����N�^�[�̊�{�I�ȋ@�\���`����
*/
class CCollider;
class CCharacter:public CTask{
public:
	CVector mPosition;//�ʒu
	CVector mRotation;//��]
	CVector mScale;//�g��k��
	CModel *mpModel;//���f���̃|�C���^
	CMatrix mMatrix;//�����s��
	CMatrix mMatrixTranslate;//���s�ړ��s��
	CMatrix mMartixRotate;//��]�s��
	CMatrix mMatrixScale;//�g��k���s��
	~CCharacter();
	CCharacter();
	//�X�V����
	void Update();
	//�`�揈��
	void Render();
	//�Փ˔���
	virtual void Collision(CCollider*mycol, CCollider*youcol){}
	enum ETag{
		ENONE,//�����l
		EPOINT,//�|�C���g
		EPLAYER,//�v���C���[
		EAIRBASE,//��R��n
		EOBJECT,//��
		EENEMYSTOP,//�W�Q�A�C�e��
	};
	ETag mTag;

	int Priority;

};
#endif