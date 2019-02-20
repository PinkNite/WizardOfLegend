#include "stdafx.h"
#include "EnemyStateDamage.h"


EnemyStateDamage::EnemyStateDamage()
{
}


EnemyStateDamage::~EnemyStateDamage()
{
}

EnemyState * EnemyStateDamage::handleState(Enemy * enemy, Enemy::ActionState state)
{
	return nullptr;
}

void EnemyStateDamage::enter(Enemy * enemy)
{
	enemy->setAction(Enemy::ActionState::IDLE, enemy->getDirection());
}

void EnemyStateDamage::update(Enemy * enemy)
{
}
