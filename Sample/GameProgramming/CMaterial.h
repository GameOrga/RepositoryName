#ifndef CMATERIAL_H
#define CMATERIAL_H
//shared_ptrのインクルード
#include<memory>
#include"CTexture.h"
/*
マテリアルクラス
マテリアルのデータを扱う
*/
class CMaterial{
public:
	std::shared_ptr<CTexture>mpTexture;
	//マテリアルを無効にする
	void Disabled();
	//マテリアル名
	char mName[64];
	//拡散光の色RGBA
	float mDiffuse[4];
	//デフォルトコンストラクタ
	CMaterial();
	//マテリアルを有効にする
	void Enabled();
	//マテリアル毎の頂点数
	int mVertexNum;
};
#endif