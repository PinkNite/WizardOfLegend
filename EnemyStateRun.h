#pragma once
#include "EnemyState.h"
class EnemyStateRun : public EnemyState
{
public:
	EnemyStateRun();
	~EnemyStateRun();

	EnemyState * handleState(Enemy * enemy, Enemy::ActionState state)		override;
	void enter(Enemy * enemy)					override;
	void update(Enemy * enemy)					override;

};

