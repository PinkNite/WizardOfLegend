#pragma once
#include "object.h"
#include "stdafx.h"
#include "animation.h"

class EnemyState;

class Enemy : public OBJECT
{
public:
	enum class DIRECTION
	{
		LEFT, RIGHT, UP, DOWN
	};

	enum class EnemyType
	{
		GHOUL, GOLEM, SUMMONER, LANCER
	};

	enum class State 
	{
		IDLE = 0,
		RUN,
		ATTACK1,
		ATTACK2,
		DAMAGE,
		DEATH,
		HIDDEN,
		MAX
	};

private:

	const int MOB_WIDTH = 40;
	const int MOB_HEIGHT = 80;

	float _fMaxHP;
	float _fCurrentHP;
	float _fSpeed;

	map<State, string> _mState;
	map<DIRECTION, string> _mDirection;

	image * _pWeaponImage;
	image * _pEffectImage;

	animation * _pAnimation;

	int _arFrame[20];
	float _timeSet;

	string		_objName;
	EnemyType	_enType;
	State		_state;
	DIRECTION	_direction;

	// 이동 방향
	float		_fAngleX;
	float		_fAngleY;

	EnemyState *	_pCurrentState;
	EnemyState *	_arState[static_cast<const int>(State::MAX)];

public:
	Enemy();
	~Enemy();

	void init();

	// override functions
	void update()			override;
	void release()			override;
	void render(HDC hdc)	override;

private:
	void createEnumNames();
	void createAnimations();

	const string getAnimaKey(const string& strDir, const string& strAction);

	void addAnimaKey(const string& strDir, const string& strAction, int startFrame, int endFrame, int fps, bool isLoop, void * cbFunction);

public:
	void setEnemy(EnemyType enType, float x, float y);
	// 맵에 출현
	void showEnemy();
	// 몹이 플레이어 인식시
	void setBattle();

	// 상태 패턴 생성
	void createStates();
	void setState(State eState);
	void setDirection(DIRECTION eDirection);
	void setAction(State eState, DIRECTION eDirection);
	void handleState(State eState, DIRECTION eDirection);
	
	void startAnimation();

	void handleKeyInput();
	void moveUp(float speed);
	void moveDown(float speed);
	void moveLeft(float speed);
	void moveRight(float speed);
	void moveEnemy();

	void skillFire(float x, float y);
	void skillMove();
	void skillRender(HDC hdc);

	void setRect();
	void setDamage(float damage);
	void setDeath();

	inline float getSpeed() { return _fSpeed; }
	inline DIRECTION getDirection() { return _direction; }
	inline animation* getAnimation() { return _pAnimation; }

	static void callbackBattle(void * obj);
	static void callbackIdle(void * obj);
};

