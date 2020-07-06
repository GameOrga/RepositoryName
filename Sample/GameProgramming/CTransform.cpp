#include"CTransform.h"
//�s��X�V����

void CTransform::Update(){
	//�g��k���s��̐ݒ�
	mMatrixScale.Scale(mScale.mX, mScale.mY, mScale.mZ);
	//��]�s��̐ݒ�
	mMartixRotate =
		CMatrix().RotateZ(mRotation.mZ)*
		CMatrix().RotateX(mRotation.mX)*
		CMatrix().RotateY(mRotation.mY);
	//���ψړ��s��̐ݒ�
	mMatrixTranslate.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
	//�����s��̐ݒ�
	mMatrix = mMatrixScale*mMartixRotate*mMatrixTranslate;
}