#pragma once
#include "stdafx.h"
#include "BossState.h"

class BossStateIdle : public BossState
{
public:
	BossStateIdle();
	~BossStateIdle();

	virtual void handleState(BOSS* boss)	override;
	virtual void update(BOSS* boss)			override;

};

