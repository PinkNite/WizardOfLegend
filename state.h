#pragma once
#include "stdafx.h"
#include "player.h"
#include "skill.h"

class STATE abstract {
public:
	virtual void onBtnW(PLAYER* pPlayer)		abstract;
	virtual void onBtnA(PLAYER* pPlayer)		abstract;
	virtual void onBtnS(PLAYER* pPlayer)		abstract;
	virtual void onBtnD(PLAYER* pPlayer)		abstract;
	virtual void onBtnQ(PLAYER* pPlayer)		abstract;
	virtual void onBtnE(PLAYER* pPlayer)		abstract;
	virtual void onBtnSpace(PLAYER* pPlayer)	abstract;
	virtual void onBtnLB(PLAYER* pPlayer)		abstract;
	virtual void onBtnRB(PLAYER* pPlayer)		abstract;
	virtual void onBtnR(PLAYER* pPlayer)		abstract;
	virtual void update(PLAYER * pPlayer)		abstract;
};