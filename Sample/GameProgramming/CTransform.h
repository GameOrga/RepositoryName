#ifndef CTRANSFORM_H
#define CTRANSFORM_H
#include"CVector.h"
/*
�g�����X�t�H�[���N���X
�ʒu�A��]�A�g�k�A�ϊ��s��̊�{�N���X
*/
class CTransform{
public:
	CVector mPosition;//�ʒu
	CVector mRotation;//��]
	CVector mScale;//�g��k��
	CMatrix mMatrix;//�����s��
	CMatrix mMatrixTranslate;//���s�ړ��s��
	CMatrix mMartixRotate;//��]�s��
	CMatrix mMatrixScale;//�g��k���s��
	//�s��X�V����
	void Update();
};
#endif