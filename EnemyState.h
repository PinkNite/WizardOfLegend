#pragma once
#include "stdafx.h"
#include "Enemy.h"

class EnemyState abstract
{
public:
	virtual EnemyState * handleState(Enemy * enemy) abstract;
	virtual void enter(Enemy * enemy)		abstract;
	virtual void update(Enemy * enemy)		abstract;
};
