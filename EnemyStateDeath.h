#pragma once
#include "EnemyState.h"
class EnemyStateDeath : public EnemyState
{
public:
	EnemyStateDeath();
	~EnemyStateDeath();

	EnemyState * handleState(Enemy * enemy, Enemy::ActionState state)		override;
	void enter(Enemy * enemy)					override;
	void update(Enemy * enemy)					override;

};

