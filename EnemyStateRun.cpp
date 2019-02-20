#include "stdafx.h"
#include "EnemyStateRun.h"


EnemyStateRun::EnemyStateRun()
{
}


EnemyStateRun::~EnemyStateRun()
{
}

EnemyState * EnemyStateRun::handleState(Enemy * enemy, Enemy::ActionState state)
{
	return nullptr;
}

void EnemyStateRun::enter(Enemy * enemy)
{
	enemy->setAction(Enemy::ActionState::RUN, enemy->getDirection());
}

void EnemyStateRun::update(Enemy * enemy)
{
	//enemy->moveEnemy();
}
