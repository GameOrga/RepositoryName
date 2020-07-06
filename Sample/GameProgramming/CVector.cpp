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
//行列とのかけ算
//Multi(行列)
CVector CVector::Multi(const CMatrix &m){
	CVector v; //戻り値用作成
	//1行1列目の計算
	v.mX = mX*m.mM[0][0] + mY*m.mM[1][0] + mZ*m.mM[2][0] + m.mM[3][0];
	v.mY= mX*m.mM[0][1] + mY*m.mM[1][1] + mZ*m.mM[2][1] + m.mM[3][1];
	v.mZ= mX*m.mM[0][2] + mY*m.mM[1][2] + mZ*m.mM[2][2] + m.mM[3][2];
	return v;//戻り値を返す
}
//*演算子のオーバーロード
//CVecor*CMatrixの演算結果を返す
CVector CVector::operator*(const CMatrix&m){
	//掛け算の結果を返す
	return Multi(m);
}
CVector CVector::operator-(const CVector &v){
	return CVector(mX - v.mX, mY - v.mY, mZ - v.mZ);
}
//ベクトルの長さを返す
float CVector::Length(){
	return sqrtf(mX*mX + mY*mY + mZ*mZ);
}
float CVector::Dot(const CVector&v){
	return (mX*v.mX + mY*v.mY + mZ*v.mZ);
}
CVector CVector::Normalize(){
	//ベクトルの大きさで割ったベクトルを返す(長さ1のベクトル)
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