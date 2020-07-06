#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include"CCharacter.h"
#include"CPlayer.h"
#include"CMap.h"
/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	static int EnemyHP;
	//2D�`��X�^�[�g
	//Start2D(�����W�A�E���W�A�����W�A����W)
	void Start2D(float left, float right, float bottom, float top);
	//2D�`��I��
	void End2D();
	CMap mMap;//�}�b�v�̃C���X�^���X
	CCharacter Character;
	CPlayer Player;
	CModel mItem;
	CModel mGate;
	CModel mWood;
	CModel mFallenTree;
	CModel mCube;
	CModel mStop;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	CSceneGame()
		: mMap(-1){}
	~CSceneGame();
};

#endif
