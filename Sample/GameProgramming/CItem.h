#ifndef CITEM_H
#define CITEM_H

#include "CModel.h"

#include "CCharacter.h"

#include "CCollider.h"

#include "CPoint.h"

class CItem :public CCharacter{
public:

	CItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider mCollider;

	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
	void Collision(CCollider*im, CCollider*y);

	static int GateCount;

	static int ItemCount;

};

class CDisturdanceItem :public CCharacter{
public:

	CDisturdanceItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider mCollider;

	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
	void Collision(CCollider*im, CCollider*y);

};

class CWood :public CCharacter{
public:

	CWood(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider mCollider;

};

class CFallenTree :public CCharacter{
public:

	CFallenTree(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider mCollider;

};

#endif
