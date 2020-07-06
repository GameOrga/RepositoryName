#include"CEffect.h"

CEffect::CEffect(const CVector&pos, float w, float h, std::shared_ptr<CTexture>texture, int row, int col, int fps)
:CBillBoard(pos, w, h), mRows(row), mCols(col), mFps(fps), mFrame(0)
{
	mMaterial.mpTexture = texture;
}

void CEffect::Update(){
	//�R�}���̌v�Z
	int frame = mFrame++ / mFps;
	frame %= (mRows*mCols);
	//UV��
	float left = 1.0f / mCols*(frame%mCols);
	//UV�E
	float right = left + 1.0f / mCols;
	//UV��
	float top = 1.0f - 1.0f / mRows*(frame / mCols);
	//UV��
	float bot = top - 1.0f / mRows;
	//�e�N�X�`���}�b�s���O
	mT[0].mUv[0] = CVector(right, top, 0.0f);
	mT[0].mUv[1] = CVector(left, bot, 0.0f);
	mT[0].mUv[2] = CVector(right, bot, 0.0f);
	mT[1].mUv[0] = CVector(left, top, 0.0f);
	mT[1].mUv[1] = CVector(left, bot, 0.0f);
	mT[1].mUv[2] = CVector(right, top, 0.0f);
	//�r���{�[�h�X�V
	CBillBoard::Update();
	if (mFrame == mCols*mRows*mFps){
		mEnabled = false;
	}
}