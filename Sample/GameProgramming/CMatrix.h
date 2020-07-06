#ifndef CMATRIX_H
#define CMATRIX_H
/*
�}�g���N�X�N���X
4�s4��̍s��f�[�^�������܂�
*/
class CMatrix{
public:
	//4�~4�̍s��f�[�^��ݒ�
	float mM[4][4];
	//�\���m�F�p
	//4�~4�̍s�����ʏo��
	void Print();
	//�f�t�H���g�R���X�g���N�^
	CMatrix();
	//�P�ʍs��̍쐬
	CMatrix Identity();
	//��]�s��(Y��)�̍쐬
	//RotateY(�p�x)
	CMatrix RotateY(float degree);
	//��]�s��(X��)�̍쐬
	//RotateX(�p�x)
	CMatrix RotateX(float degree);
	//��]�s��(Z��)�̍쐬
	//RotateZ(�p�x)
	CMatrix RotateZ(float degree);
	//���s�ړ��s��̍쐬
	//Translate(�ړ���X,�ړ���Y,�ړ���Z)
	CMatrix Translate(float x, float y, float z);
	//�g��k���s��̍쐬
	//Scale(�{��X,�{��Y,�{��Z)
	CMatrix Scale(float sx, float sy, float sz);
	//*	���Z�q�̃I�[�o�[���[�h
	//CMatrix *CMatrix �̉��Z���ʂ�Ԃ�
	CMatrix operator*(const CMatrix &m);
};
#endif