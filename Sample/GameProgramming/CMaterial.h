#ifndef CMATERIAL_H
#define CMATERIAL_H
//shared_ptr�̃C���N���[�h
#include<memory>
#include"CTexture.h"
/*
�}�e���A���N���X
�}�e���A���̃f�[�^������
*/
class CMaterial{
public:
	std::shared_ptr<CTexture>mpTexture;
	//�}�e���A���𖳌��ɂ���
	void Disabled();
	//�}�e���A����
	char mName[64];
	//�g�U���̐FRGBA
	float mDiffuse[4];
	//�f�t�H���g�R���X�g���N�^
	CMaterial();
	//�}�e���A����L���ɂ���
	void Enabled();
	//�}�e���A�����̒��_��
	int mVertexNum;
};
#endif