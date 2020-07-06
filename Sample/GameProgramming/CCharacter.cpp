#include"CCharacter.h"
#include"CTaskManager.h"
CCharacter::CCharacter()
:mpModel(0), mTag(ENONE)
{
	//�^�X�N���X�g�ɒǉ�
	TaskManager.Add(this);
}
//�X�V����
void CCharacter::Update(){
	//�g��k���s��̐ݒ�
	mMatrixScale.Scale(mScale.mX, mScale.mY, mScale.mZ);
	//��]�s��̐ݒ�
	mMartixRotate =
		CMatrix().RotateZ(mRotation.mZ)*
		CMatrix().RotateX(mRotation.mX)*
		CMatrix().RotateY(mRotation.mY);
	//���s�ړ��s��̐ݒ�
	mMatrixTranslate.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
	//�����s��̐ݒ�
	mMatrix = mMatrixScale*mMartixRotate*mMatrixTranslate;
}
//�`�揈��
void CCharacter::Render(){
	//mpModel��0�ȊO�Ȃ�`��
	if (mpModel){
		//���f���̕`��
		mpModel->Render(mMatrix);
	}
}
CCharacter::~CCharacter(){
	//�^�X�N���X�g����̍폜
	TaskManager.Remove(this);
}