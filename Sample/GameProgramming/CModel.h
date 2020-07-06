#ifndef CMODEL_H
#define CMODEL_H
#include"CTriangle.h"
#include<vector>
#include"CMaterial.h"
//三角形の可変長配列
/*
モデルクラス
モデルデータの入力や表示
*/
class CModel{
public:
	//モデルファイルの入力
	//Load(モデルファイル名、マテリアルファイル名)
	void Load(char*obj, char*mtl);
	//三角形のの可変長配列
	std::vector<CTriangle> mTriangle;
	std::vector<CMaterial> mMaterial;
	std::vector<CVector>uv;
	//描画
	void Render();
	//Render(合成行列)
	void Render(const CMatrix &m);
	//頂点配列
	float*mpVertex;//頂点座標
	float*mpNormal;//法線
	float*mpTextureCoord;//テクスチャマッピング
	//デフォルトコンストラクタ
	CModel();
	//デストラクタ
	~CModel();
};
#endif