#pragma once
#include "EnemyState.h"

class EnemyStateSkill1 : public EnemyState
{
public:
	EnemyStateSkill1();
	~EnemyStateSkill1();

	virtual EnemyState * handleState(Enemy * enemy, Enemy::ActionState state)		override;
	virtual void enter(Enemy * enemy)					override;
	virtual void update(Enemy * enemy)					override;
};

