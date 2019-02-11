#pragma once
#include "stdafx.h"
#include "boss.h"

class BossState abstract
{
public:
	virtual BossState* handleState(BOSS * boss, BOSS::BOSS_STATE state)	abstract;
	virtual void enter(BOSS * boss)				abstract;
	virtual void update(BOSS * boss)			abstract;
};

