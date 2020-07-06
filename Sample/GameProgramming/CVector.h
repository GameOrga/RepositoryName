#ifndef CVECTOR_H
#define CVECTOR_H
#include"CMatrix.h"
/*
ベクトルクラス
ベクトルデータを扱います
*/
class CVector{
public:
	//内積
	float Dot(const CVector&v);
	//3D各軸での値を設定
	float mX, mY, mZ;
	//各軸での値の設定
	//Set(X座標,Y座標,Z座標)
	void Set(float x, float y, float z);
	//行列とのかけ算
	//Multi(行列)
	CVector Multi(const CMatrix&m);
	//デフォルトコンストラクタ
	CVector();
	//コンストラクタ
	//CVector(X座標,Y座標,Z座標)
	CVector(float x, float y, float z);
	//*演算子のオーバーロード
	//CVector+CVectorの演算結果を返す
	CVector operator+(const CVector&v);
	//CVector *CMatrixの演算結果を返す
	CVector operator*(const CMatrix&m);
	//-演算しのオーバーロード
	//CVector-CVectorの演算結果を返す
	CVector operator-(const CVector&v);
	//ベクトルの長さを返す
	float Length();
	//外積
	//Cross(ベクトル)
	CVector Cross(const CVector&v);
	//*演算子のオーバーロード
	CVector operator*(const float&f);
	//正規化
	CVector Normalize();
};
#endif