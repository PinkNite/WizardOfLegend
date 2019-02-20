#pragma once
#include "object.h"
#include "stdafx.h"
#include "animation.h"
#include "aStar.h"

class MAP;
class PLAYER;
class CAMERA;
class EnemyState;

class Enemy : public OBJECT
{
public:
	enum class DIRECTION
	{
		LEFT, RIGHT
	};

	enum class MOVE
	{
		LEFT, RIGHT, UP, DOWN
	};

	enum class EnemyType
	{
		GHOUL, GOLEM, SUMMONER//, LANCER
	};

	enum class ActionState 
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

	int MOB_RECT_WIDTH = 40;
	int MOB_RECT_HEIGHT = 80;

	float _fMaxHP;
	float _fCurrentHP;
	float _fSpeed;

	map<ActionState, string> _mState;
	map<DIRECTION, string> _mDirection;

	image * _pWeaponImage;
	image * _pEffectImage;

	animation * _pAnimation;

	int			_arFrame[20];
	float		_timeSet;
	
	// 이동 방향
	float		_fAngleX;
	float		_fAngleY;
	float		_fDamage;
	float		_targetDistance;


	string		_objName;
	EnemyType	_enType;
	ActionState	_state;
	DIRECTION	_direction;
	MOVE		_move;

	EnemyState *	_pCurrentState;
	EnemyState *	_arState[static_cast<const int>(ActionState::MAX)];

	MAP *		_pMap;
	ASTAR *		_pAstar;
	PLAYER *	_pPlayer;
	CAMERA *	_pCamera;
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
	void setMap(MAP* pMap) { _pMap = pMap; }
	void setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }
	void setCameraLink(CAMERA* pCamera) { _pCamera = pCamera; }

	// 몹 종류, 위치 설정
	void setEnemy(EnemyType enType, float x, float y);

	// 맵에 출현
	void showEnemy();
	// 몹이 플레이어 인식시
	void setBattle();

	// 상태 패턴 생성
	void createStates();
	void setState(ActionState eState);
	void setDirection(DIRECTION eDirection);
	void setAction(ActionState eState, DIRECTION eDirection);
	
	void startAnimation();

	void handleKeyInput();
	void moveUp(float speed);
	void moveDown(float speed);
	void moveLeft(float speed);
	void moveRight(float speed);
	void moveEnemy();

	void skillAttack(float x, float y);
	void skillMove();
	void skillRender(HDC hdc);

	void setRect();
	void setDamage(float damage);
	void setDeath();

	LPCRECT getCollisionRect() { return &_rc; }

	inline float getSpeed() { return _fSpeed; }
	inline DIRECTION getDirection() { return _direction; }
	inline animation* getAnimation() { return _pAnimation; }

};

