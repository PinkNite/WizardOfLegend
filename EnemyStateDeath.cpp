#include "stdafx.h"
#include "EnemyStateDeath.h"


EnemyStateDeath::EnemyStateDeath()
{
}


EnemyStateDeath::~EnemyStateDeath()
{
}

EnemyState * EnemyStateDeath::handleState(Enemy * enemy, Enemy::ActionState state)
{
	return nullptr;
}

void EnemyStateDeath::enter(Enemy * enemy)
{
	enemy->setAction(Enemy::ActionState::DEATH, enemy->getDirection());
}

void EnemyStateDeath::update(Enemy * enemy)
{
}
