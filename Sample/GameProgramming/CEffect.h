#ifndef CEFFECT_H
#define CEFFECT_H
//ビルボードクラスのインクルード
#include"CBillBoard.h"
/*
エフェクトクラス
テクスチャのアニメーション
*/
class CEffect :public CBillBoard{
public:
	//行列
	int mRows;
	//列数
	int mCols;
	//1コマのフレーム数
	int mFps;
	//フレームカウンタ
	int mFrame;

	//コンストラクタ
	//CEffect(位置、幅、高さ、テクスチャ、行数、列数、1コマ当たりのフレーム数)行列、列数、フレーム数はデフォルト引数で呼出し時省略可能
	CEffect(const CVector&pos, float w, float h, std::shared_ptr<CTexture>texture, int row = 1, int col = 1, int fps = 1);
	//更新
	void Update();
};
#endif