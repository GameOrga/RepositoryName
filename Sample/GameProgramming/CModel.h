#ifndef CMODEL_H
#define CMODEL_H
#include"CTriangle.h"
#include<vector>
#include"CMaterial.h"
//�O�p�`�̉ϒ��z��
/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel{
public:
	//���f���t�@�C���̓���
	//Load(���f���t�@�C�����A�}�e���A���t�@�C����)
	void Load(char*obj, char*mtl);
	//�O�p�`�̂̉ϒ��z��
	std::vector<CTriangle> mTriangle;
	std::vector<CMaterial> mMaterial;
	std::vector<CVector>uv;
	//�`��
	void Render();
	//Render(�����s��)
	void Render(const CMatrix &m);
	//���_�z��
	float*mpVertex;//���_���W
	float*mpNormal;//�@��
	float*mpTextureCoord;//�e�N�X�`���}�b�s���O
	//�f�t�H���g�R���X�g���N�^
	CModel();
	//�f�X�g���N�^
	~CModel();
};
#endif