#pragma once
#include "stdafx.h"
#include "boss.h"

class BossState abstract
{
public:
	virtual void handleState(BOSS* boss)	abstract;
	virtual void update(BOSS* boss)			abstract;
};

