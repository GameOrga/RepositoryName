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
	//衝突判定
	//（コライダ1、コライダ2）
	void Collision(CCollider*im, CCollider*y);


};




#endif
