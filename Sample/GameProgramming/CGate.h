#ifndef CGATE_H
#define CGATE_H

#include "CModel.h"

#include "CCharacter.h"

#include "CCollider.h"

#include "CPoint.h"

class CGate :public CCharacter{
public:

	CGate(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider mGateB;
	static int CG;
	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
	void Collision(CCollider*im, CCollider*y);


};




#endif
