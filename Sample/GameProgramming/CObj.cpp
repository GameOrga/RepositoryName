#include"CObj.h"
//�R���X�g���N�^
//model:���f���̃|�C���^ posision �ʒu rotattion ��] scale �g��
CObj::CObj(CModel*model, const CVector&position, const
	CVector&rotation, const CVector&scale)
	:mpCollider(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//���f���̎O�p�`�̐����A�R���C�_�̔z����쐬���܂�
	mpCollider = new CCollider[model->mTriangle.size()];
	for (int i = 0; i < model->mTriangle.size(); i++){
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă����܂�
		mpCollider[i].SetTriangle(this,
			model->mTriangle[i].mV[0],
			model->mTriangle[i].mV[1],
			model->mTriangle[i].mV[2]);

	}
}

//�f�X�g���N�^
CObj::~CObj(){
	//�R���C�_������΍폜
	if (mpCollider){
		//delete[]�z����폜
		delete[] mpCollider;
	}
}