#include "stdafx.h"
#include "EnemyStateIdle.h"


EnemyStateIdle::EnemyStateIdle()
{
}


EnemyStateIdle::~EnemyStateIdle()
{
}

EnemyState * EnemyStateIdle::handleState(Enemy * enemy, Enemy::ActionState state)
{
	return nullptr;
}

void EnemyStateIdle::enter(Enemy * enemy)
{
	enemy->setAction(Enemy::ActionState::IDLE, enemy->getDirection());
}

void EnemyStateIdle::update(Enemy * enemy)
{
}
