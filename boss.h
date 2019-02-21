#pragma once
#include "object.h"
#include "stdafx.h"
#include "animation.h"
#include "throwIceSpear.h"
#include "UI.h"

class PLAYER;
class BossState;
class MAGICMGR;

class BOSS : public OBJECT
{
public:
	enum class DIRECTION
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		MAX
	};
	//
	enum class ACTION
	{
		IDLE = 0,
		RUN,
		DASH,
		SKILL_01,
		SKILL_02,
		SKILL_03,

		ENTRANCE,
		MINIMIZE,
		MAXIMIZE,
		ICED_OUT,
		DAMAGE,
		DEATH,
		READY,
		MAX
	};

	enum class SKILL_TYPE
	{
		NONE,
		CHAKRAM,
		LANCE,
		DAGGER,
		BLIZZARD,
		BUBBLE,
	};

	enum class BOSS_STATE
	{
		IDLE = 0,
		RUN,
		DASH,
		SKILL_01,
		SKILL_02,
		SKILL_03,
		ENTRANCE,
		DAMAGE,
		DEATH,
		MAX
	};

	struct tagBullet {
		image* iceImage;
		float distance;
		float angle;
		float fireAngle;
		float speed;
		float x;
		float y;
		int radius;
		bool isFire;
	};

private:
	const int BOSS_IMAGE_WIDTH = 1650;
	const int BOSS_IMAGE_HEIGHT = 2000;
	const int BOSS_MAX_FRAME_X = 11;
	const int BOSS_MAX_FRAME_Y = 10;
	const int BOSS_RECT_WIDTH = 70;
	const int BOSS_RECT_HEIGHT = 140; // FrameSize: 150, 200

	UI*	  _pUi;

	float _fMaxHP;
	float _fCurrentHP;
	float _fSpeed;

	map<ACTION, string> _mAction;
	map<DIRECTION, string> _mDirection;

	image* _pWingImage;
	image* _pEffectImage;
	image* _pBlastImage;

	animation* _pAnimation;
	animation* _pWingsAnimation;
	animation* _pEffectAnimation;
	animation* _pIceblastAnimation;
	animation* _pIceBulletAnimation;

	// bullet
	int			_bulletSize;
	bool		_isEndSkill;
	tagBullet*	_bullet[18];
	SKILL_TYPE	_skillType;

	// 프레임
	int			_arFrame[20];
	float		_timeSet;
	float		_moveTimeStart;
	float		_moveTimeEnd;

	ACTION		_action;
	DIRECTION	_direction;
	string		_objectName;

	// 이동 방향
	float		_fAngleX;
	float		_fAngleY;

	// 타겟 좌표
	float		_targetX;
	float		_targetY;
	float		_dashSpeed;
	float		_targetAngle;

	BossState*	_pCurrentState;
	BossState*	_arState[static_cast<const int>(BOSS_STATE::MAX)];

	PLAYER *	_pPlayer;
	CAMERA *	_pCamera;
	MAGICMGR*   _pMagicMgr;
	throwIceSpear* _pIceSpear;

public:
	BOSS();
	~BOSS();

	void init();

	// object 함수
	void update()			override;
	void release()			override;
	void render(HDC hdc)	override;

private:
	void setEnumName();
	void createAnimation();

	const string getAnimationKey(const string& strDir, const string& strAction);

	void addBossKeyAni(const string& strDir, const string& strAction, int startFrame, int endFrame, int fps, bool isLoop, void * cbFunction);

public:
	void showBoss();
	void setBattle();

	void setPlayer(PLAYER * pPlayer) { _pPlayer = pPlayer; }
	void setCameraLink(CAMERA* pCamera) { _pCamera = pCamera; }
	void setMagicMgr(MAGICMGR* pMagicMgr) { _pMagicMgr = pMagicMgr; }

	// state pattern
	void initState();
	void setState(BOSS_STATE bossState);
	void setAction(ACTION action, DIRECTION direction);
	void setDirection(DIRECTION direction);
	void handleState(BOSS_STATE bossState);

	void startBossAnimation();

	void handleInputKey();
	void moveUp(float speed);
	void moveDown(float speed);
	void moveLeft(float speed);
	void moveRight(float speed);

	void dash(float targetX, float targetY);
	void skillFire(float x, float y);
	void spell01(SKILL_TYPE type);
	void spell02(SKILL_TYPE type);
	void spell03(SKILL_TYPE type);
	void bulletMove();
	void bulletRender(HDC hdc);
	void setRect();
	//void moveBoss();
	void setWings(bool isMax);
	void setBossIdle();
	void setDamage(float damage);
	void setDeath();

	inline float getSpeed() { return _fSpeed; }
	inline DIRECTION getDiretion() { return _direction; }
	inline animation* getAni() { return _pAnimation; }

	LPCRECT getCollisionRect() { return &_rc; }

	static void callbackSetBattle(void * obj);
	static void callbackMinWingIdle(void * obj);
	static void callbackMaxWingIdle(void * obj);
	static void callbackIdle(void * obj);
};

