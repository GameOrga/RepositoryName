#ifndef CPLAYER_H
#define CPLAYER_H
//#define G (1.0f/60.0f)
//#define JUMPV0 (0.4f)
//�L�����N�^�N���X�̃C���N���[�h
#include"CCharacter.h"
#include"CCollider.h"
#include"CEffect.h"
/*
�v���C���[�N���X�̃C���N���[�h
#include"CCharacter.h
*/


class CPlayer:public CCharacter{
public:
	CPlayer*mpPoint;//�ڎw���|�C���g
	float mVelovcityJump;
	int cool = 0;
	int Dash=0;
	int FireCount;
	static CPlayer*mPlayer;
	//�Փ˔���
	void Collision(CCollider*mc, CCollider*yc);
	CPlayer();
	//�R���C�_
	CCollider mCollider;
	CCollider mLine[4];//�����R���C�_
	//�X�V����
	void Update();
};
#endif