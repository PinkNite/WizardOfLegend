#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy() :
	_fMaxHP(100.0f),
	_fCurrentHP(100.0f),
	_fSpeed(20.0f),
	_pAnimation(nullptr),
	_arFrame{ 0, },
	_direction(DIRECTION::DOWN),
	_action(EnemyState::IDLE),
	_fAngleX(0.0f),
	_fAngleY(0.0f)
{
}

Enemy::~Enemy()
{
}

void Enemy::init()
{
	IMAGEMANAGER->addFrameImage("Ghoul", "resource/enemy/ghoul.bmp", 600, 700, 6, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Golem", "resource/enemy/Golem.bmp", 720, 700, 6, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Summoner", "resource/enemy/SummonerSource.bmp", 500, 800, 5, 8, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Lancer", "resource/enemy/lancer.bmp", 491, 840, 6, 7, true, RGB(255, 0, 255));

	_timeSet = 0.0f;
	_objName = "Enemey";
	_pAnimation = new animation();

	createStates();
	createEnumNames();
	createAnimations();

	setAction(EnemyState::IDLE, DIRECTION::DOWN);
	startAnimation();
	

}

void Enemy::update()
{
}

void Enemy::release()
{
}

void Enemy::render(HDC hdc)
{
}

void Enemy::createEnumNames()
{
}

void Enemy::createAnimations()
{
}

const string Enemy::getAnimaKey(const string & strDir, const string & strAction)
{
	return string();
}

void Enemy::addAnimaKey(const string & strDir, const string & strAction, int startFrame, int endFrame, int fps, bool isLoop, void * cbFunction)
{
}

void Enemy::setEnemy(EnemyType enType, float x, float y)
{
	_enType = enType;

	switch (_enType)
	{
	case Enemy::EnemyType::GHOUL:
		_fSpeed = 200.0f;
		_fMaxHP = 200.0f;
		_fCurrentHP = _fMaxHP;
		OBJECT::init(x, y, MOB_WIDTH, MOB_HEIGHT);
		OBJECT::_pImg = IMAGEMANAGER->findImage("Ghoul");
		_pAnimation->init(600, 700, 100, 100);  // frameXY: 6, 7
		break;
	case Enemy::EnemyType::GOLEM:
		_fSpeed = 100.0f;
		_fMaxHP = 400.0f;
		_fCurrentHP = _fMaxHP;
		OBJECT::init(x, y, MOB_WIDTH, MOB_HEIGHT);
		OBJECT::_pImg = IMAGEMANAGER->findImage("Golem");
		_pAnimation->init(720, 700, 120, 140);	// frameXY: 6, 5
		break;
	case Enemy::EnemyType::SUMMONER:
		_fSpeed = 200.0f;
		_fMaxHP = 300.0f;
		_fCurrentHP = _fMaxHP;
		OBJECT::init(x, y, MOB_WIDTH, MOB_HEIGHT);
		OBJECT::_pImg = IMAGEMANAGER->findImage("Summoner");
		_pAnimation->init(500, 800, 100, 100);	// frameXY: 5, 8
		break;
	}

}

void Enemy::showEnemy()
{

}

void Enemy::setBattle()
{
}

void Enemy::createStates()
{
}

void Enemy::setState(EnemyState eState)
{
}

void Enemy::setDirection(DIRECTION eDirection)
{
}

void Enemy::setAction(EnemyState eState, DIRECTION eDirection)
{
}

void Enemy::handleState(EnemyState eState, DIRECTION eDirection)
{
}

void Enemy::startAnimation()
{
}

void Enemy::handleKeyInput()
{
}

void Enemy::moveUp(float speed)
{
}

void Enemy::moveDown(float speed)
{
}

void Enemy::moveLeft(float speed)
{
}

void Enemy::moveRight(float speed)
{
}

void Enemy::moveEnemy()
{
}

void Enemy::skillFire(float x, float y)
{
}

void Enemy::skillMove()
{
}

void Enemy::skillRender(HDC hdc)
{
}

void Enemy::setRect()
{
}

void Enemy::setDamage(float damage)
{
}

void Enemy::setDeath()
{
}

void Enemy::callbackBattle(void * obj)
{
}

void Enemy::callbackIdle(void * obj)
{
}
