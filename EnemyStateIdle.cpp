#include "stdafx.h"
#include "EnemyStateIdle.h"


EnemyStateIdle::EnemyStateIdle()
{
}


EnemyStateIdle::~EnemyStateIdle()
{
}

EnemyState * EnemyStateIdle::handleState(Enemy * enemy, Enemy::State state)
{
	return nullptr;
}

void EnemyStateIdle::enter(Enemy * enemy)
{
	enemy->setAction(Enemy::State::IDLE, Enemy::DIRECTION::RIGHT);
}

void EnemyStateIdle::update(Enemy * enemy)
{
}
