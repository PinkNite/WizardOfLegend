#pragma once

#include "stdafx.h"
#include "state.h"

class STATE_SKILL_ONE : public STATE {
private:
	float _fCoolTime;
	float _fWaitTime;
	int		_nCount;
	bool	_bIsUse;
public:
	STATE_SKILL_ONE();
	~STATE_SKILL_ONE();

public:
	virtual void onBtnW(PLAYER* pPlayer)		override;
	virtual void onBtnA(PLAYER* pPlayer)		override;
	virtual void onBtnS(PLAYER* pPlayer)		override;
	virtual void onBtnD(PLAYER* pPlayer)		override;
	virtual void onBtnQ(PLAYER* pPlayer)		override;
	virtual void onBtnE(PLAYER* pPlayer)		override;
	virtual void onBtnLB(PLAYER* pPlayer)		override;
	virtual void onBtnRB(PLAYER* pPlayer)		override;
	virtual void onBtnR(PLAYER* pPlayer)		override;
	virtual void onBtnSpace(PLAYER* pPlayer)	override;
	virtual void update(PLAYER * pPlayer)		override;

};