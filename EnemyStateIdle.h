#pragma once
#include "stdafx.h"
#include "EnemyState.h"

class EnemyStateIdle : public EnemyState
{
public:
	EnemyStateIdle();
	~EnemyStateIdle();

	EnemyState * handleState(Enemy * enemy, Enemy::State state)		override;
	void enter(Enemy * enemy)					override;
	void update(Enemy * enemy)					override;

};

