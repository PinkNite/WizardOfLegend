#pragma once

#include "stdafx.h"
#include "state.h"

class STATE_DASH : public STATE {
private:

public:
	STATE_DASH();
	~STATE_DASH();

public:
	virtual void onBtnW(PLAYER* pPlayer)		override;
	virtual void onBtnA(PLAYER* pPlayer)		override;
	virtual void onBtnS(PLAYER* pPlayer)		override;
	virtual void onBtnD(PLAYER* pPlayer)		override;
	virtual void onBtnQ(PLAYER* pPlayer)		override;
	virtual void onBtnE(PLAYER* pPlayer)		override;
	virtual void onBtnSpace(PLAYER* pPlayer)	override;
	virtual void onBtnLB(PLAYER* pPlayer)		override;
	virtual void onBtnRB(PLAYER* pPlayer)		override;
	virtual void onBtnR(PLAYER* pPlayer)		override;
	virtual void update(PLAYER* pPlayer)		override;


};