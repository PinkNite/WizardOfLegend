#pragma once
#include "EnemyState.h"

class EnemyStateDamage : public EnemyState
{
public:
	EnemyStateDamage();
	~EnemyStateDamage();

	virtual EnemyState * handleState(Enemy * enemy, Enemy::ActionState state)		override;
	virtual void enter(Enemy * enemy)					override;
	virtual void update(Enemy * enemy)					override;
};

