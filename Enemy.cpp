#include "stdafx.h"
#include "Enemy.h"
#include "EnemyStateIdle.h"


Enemy::Enemy() :
	_fMaxHP(100.0f),
	_fCurrentHP(100.0f),
	_fSpeed(20.0f),
	_pAnimation(nullptr),
	_arFrame{ 0, },
	_direction(DIRECTION::DOWN),
	_state(State::IDLE),
	_fAngleX(0.0f),
	_fAngleY(0.0f)
{
}

Enemy::~Enemy()
{
}

void Enemy::init()
{
	IMAGEMANAGER->addFrameImage("Ghoul", "resource/enemy/ghoul.bmp", 600, 600, 6, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Golem", "resource/enemy/Golem.bmp", 720, 700, 6, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Summoner", "resource/enemy/SummonerSource.bmp", 500, 800, 5, 8, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Lancer", "resource/enemy/lancer.bmp", 491, 840, 6, 7, true, RGB(255, 0, 255));

	_timeSet = 0.0f;
	_objName = "Enemey";
	_pAnimation = new animation();

	createStates();
	createEnumNames();
	createAnimations();

	setAction(State::HIDDEN, DIRECTION::DOWN);
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
	if (State::HIDDEN != _state)
	{
		//OBJECT::_pImg->aniRenderCenter(  fasdf );
	}
}

void Enemy::createEnumNames()
{
	_mDirection.insert(make_pair(DIRECTION::LEFT, "LEFT"));
	_mDirection.insert(make_pair(DIRECTION::RIGHT, "RIGHT"));
	_mDirection.insert(make_pair(DIRECTION::UP, "BACK"));
	_mDirection.insert(make_pair(DIRECTION::DOWN, "DOWN"));

	_mState.insert(make_pair(State::IDLE, "IDLE"));
	_mState.insert(make_pair(State::RUN, "RUN"));

	_mState.insert(make_pair(State::ATTACK1, "ATTACK1"));
	_mState.insert(make_pair(State::ATTACK2, "ATTACK2"));
	
	_mState.insert(make_pair(State::DAMAGE, "DAMAGE"));
	_mState.insert(make_pair(State::DEATH, "DEATH"));
	_mState.insert(make_pair(State::HIDDEN, "HIDDEN"));

}

void Enemy::createAnimations()
{
	KEYANIMANAGER->addObject(_objName);
	// ghoul
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::IDLE], 5, 5, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::IDLE], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::RUN], 6, 11, 8, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::RUN], 17, 12, 8, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::ATTACK1], 4, 3, 4, false, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::ATTACK1], 1, 2, 4, false, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::ATTACK2], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::ATTACK2], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::DAMAGE], 35, 35, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::DAMAGE], 18, 18, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::DEATH], 35, 27, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::DEATH], 18, 26, 4, true, nullptr);


	// Golem
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::IDLE], 5, 5, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::IDLE], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::RUN], 6, 11, 8, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::RUN], 17, 12, 8, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::ATTACK1], 4, 3, 4, false, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::ATTACK1], 1, 2, 4, false, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::ATTACK2], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::ATTACK2], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::DAMAGE], 17, 17, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::DAMAGE], 11, 11, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::DEATH], 29, 24, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::DEATH], 18, 23, 4, true, nullptr);


	// summoner
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::IDLE], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::IDLE], 10, 10, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::RUN], 0, 2, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::RUN], 10, 12, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::ATTACK1], 3, 9, 4, false, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::ATTACK1], 13, 19, 4, false, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::ATTACK2], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::ATTACK2], 0, 0, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::DAMAGE], 34, 34, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::DAMAGE], 20, 20, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::LEFT], _mState[State::DEATH], 34, 28, 4, true, nullptr);
	addAnimaKey(_mDirection[DIRECTION::RIGHT], _mState[State::DEATH], 20, 26, 4, true, nullptr);

}

const string Enemy::getAnimaKey(const string & strDir, const string & strAction)
{
	string temp = "";
	temp.append(strDir);
	temp.append("_");
	temp.append(strAction);
	return temp;
}

void Enemy::addAnimaKey(const string & strDir, const string & strAction, int startFrame, int endFrame, int fps, bool isLoop, void * cbFunction)
{
	int nFrameCount(0);
	int nFrameTmp(0);

	nFrameTmp = startFrame;
	if (nFrameTmp > endFrame)
	{
		while (nFrameTmp >= endFrame)
		{
			_arFrame[nFrameCount] = nFrameTmp;
			nFrameTmp--;
			nFrameCount++;
		}
	}
	else
	{
		while (nFrameTmp <= endFrame)
		{
			_arFrame[nFrameCount] = nFrameTmp;
			nFrameTmp++;
			nFrameCount++;
		}
	}

	string imageName = "";
	switch (_enType)
	{
	case Enemy::EnemyType::GHOUL:
		imageName = "Ghoul";
		break;
	case Enemy::EnemyType::GOLEM:
		imageName = "Golem";
		break;
	case Enemy::EnemyType::SUMMONER:
		imageName = "Summoner";
		break;
	}

	if (cbFunction == nullptr)
	{
		KEYANIMANAGER->addArrayFrameAnimation(_objName, getAnimaKey(strDir, strAction),
			imageName.c_str(), _arFrame, nFrameCount, fps, isLoop);
	}
	else
	{
		KEYANIMANAGER->addArrayFrameAnimation(_objName, getAnimaKey(strDir, strAction),
			imageName.c_str(), _arFrame, nFrameCount, fps, isLoop, cbFunction, this);
	}
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
	setState(State::IDLE);
}

void Enemy::setBattle()
{
}

void Enemy::createStates()
{
	_arState[int(State::IDLE)] = new EnemyStateIdle();

}

void Enemy::setState(State eState)
{
	_state = eState;
}

void Enemy::setDirection(DIRECTION eDirection)
{
	_direction = eDirection;
}

void Enemy::setAction(State eState, DIRECTION eDirection)
{
	setState(eState);
	_direction = eDirection;
}

void Enemy::handleState(State eState, DIRECTION eDirection)
{
}

void Enemy::startAnimation()
{
	_pAnimation = KEYANIMANAGER->findAnimation(_objName, getAnimaKey(_mDirection[_direction], _mState[_state]));
	_pAnimation->start();
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
