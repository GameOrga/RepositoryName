#include"CVector.h"
#include<math.h>
CVector::CVector()
:mX(0.0f), mY(0.0f), mZ(0.0f)
{}
CVector::CVector(float x, float y, float z){
	mX = x, mY = y, mZ = z;
}
void CVector::Set(float x,float y,float z){
	mX = x;
	mY = y;
	mZ = z;
}
//�s��Ƃ̂����Z
//Multi(�s��)
CVector CVector::Multi(const CMatrix &m){
	CVector v; //�߂�l�p�쐬
	//1�s1��ڂ̌v�Z
	v.mX = mX*m.mM[0][0] + mY*m.mM[1][0] + mZ*m.mM[2][0] + m.mM[3][0];
	v.mY= mX*m.mM[0][1] + mY*m.mM[1][1] + mZ*m.mM[2][1] + m.mM[3][1];
	v.mZ= mX*m.mM[0][2] + mY*m.mM[1][2] + mZ*m.mM[2][2] + m.mM[3][2];
	return v;//�߂�l��Ԃ�
}
//*���Z�q�̃I�[�o�[���[�h
//CVecor*CMatrix�̉��Z���ʂ�Ԃ�
CVector CVector::operator*(const CMatrix&m){
	//�|���Z�̌��ʂ�Ԃ�
	return Multi(m);
}
CVector CVector::operator-(const CVector &v){
	return CVector(mX - v.mX, mY - v.mY, mZ - v.mZ);
}
//�x�N�g���̒�����Ԃ�
float CVector::Length(){
	return sqrtf(mX*mX + mY*mY + mZ*mZ);
}
float CVector::Dot(const CVector&v){
	return (mX*v.mX + mY*v.mY + mZ*v.mZ);
}
CVector CVector::Normalize(){
	//�x�N�g���̑傫���Ŋ������x�N�g����Ԃ�(����1�̃x�N�g��)
	return*this*(1.0f / Length());
}
CVector CVector::Cross(const CVector&v){
	return CVector(mY*v.mZ - mZ*v.mY, mZ*v.mX - mX*v.mZ, mX*v.mY - mY*v.mX);
}
CVector CVector::operator*(const float&f){
	return CVector(mX*f, mY*f, mZ*f);
}
CVector CVector::operator+(const CVector&v){
	return CVector(mX + v.mX, mY + v.mY, mZ + v.mZ);
}