#pragma once
#include "stdafx.h"
#include "EnemyState.h"

class EnemyStateIdle : public EnemyState
{
public:
	EnemyStateIdle();
	~EnemyStateIdle();

	virtual EnemyState * handleState(Enemy * enemy, Enemy::ActionState state)		override;
	virtual void enter(Enemy * enemy)					override;
	virtual void update(Enemy * enemy)					override;
};

