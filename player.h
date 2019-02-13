#pragma once

#include "object.h"
#include "stdafx.h"
#include "animation.h"
#include "circleEffect.h"

class STATE;
class SKILL;
class MAGICMGR;
class SKILL_EFFECT_MGR;


class PLAYER : public OBJECT
{
public:
	//애니메이션 용
	enum class DIRECTION
	{
		FORWARD = 0,
		RIGHT,
		LEFT,
		BACK,
		MAX
	};
	//애니메이션 용
	enum class ACTION
	{
		IDLE = 0,
		RUN,
		DASH,
		ATTACK_MOTION_01,
		ATTACK_MOTION_02,
		ATTACK_MOTION_03,
		ATTACK_MOTION_04,
		DAMAGE,
		DEATH,
		MAX
	};

	//상태용
	enum class PLAYER_STATE
	{
		IDLE = 0,
		RUN,
		DASH,
		SKILL_01,
		SKILL_02,
		SKILL_03,
		SKILL_04,
		SKILL_05,
		DAMAGE,
		DEATH,
		MAX
	};

	//이동용
	enum class MOVE_DIRECTION
	{
		NONE = 0,
		LEFT,
		RIGHT,
		TOP,
		BOTTOM,
		LEFT_TOP,
		LEFT_BOTTOM,
		RIGHT_TOP,
		RIGHT_BOTTOM,
		MAX
	};


	enum { WIZARD_SPRITE_WIDTH = 2688 };
	enum { WIZARD_SPRITE_HEIGHT = 3072 };
	enum { WIZARD_SPRITE_MAXFRAMEX = 14 };
	enum { WIZARD_SPRITE_MAXFRAMEY = 16 };

	enum { WIZARD_MOVING_RECT_SIZE = 64};

	enum { WIZARD_COLLISION_RECT_WIDTH = 64};
	enum { WIZARD_COLLISION_RECT_HEIGHT = 128 };

	
private:
	float _fMaxHealthPoint;			//최대 생명력
	float _fCurrentHealthPoint;		//현재 생명력
	float _fSpeed;					//속도
	float _fArmor;					//방어력
	float _fEvasion;				//회피율
	float _fCriticalHit;			//치명타율


	//위자드오브레전드는 이동 타일을 확인하는 용의 사각형과 중앙값을 따로 가지고 있어야한다.
	//플레이어를 가볍게 상하로 구분하고 아래 사각형을 이동시 충돌 렉트로 한다

	float _fSkillDelayTime[6];			//스킬 딜레이 시간//스킬 세팅된것이 6개 있다고 치자...

	// 방향과 액션의 이름
	string _arDirection[static_cast<const int>(DIRECTION::MAX)];
	string _arAction[static_cast<const int>(ACTION::MAX)];

	RECT	_rcMovingCollision;
	RECT	_rcDamageCollision;
	//오브젝트의 사각형은 없는 취급 할것이다.
	//이미지 사이즈가 오브젝트에 비해 월등이 크기 때문이다.

	animation* _pAnimation;
	
	//프레임
	int _arFrame[12];

	DIRECTION	_direction;
	ACTION		_action;
	string		_strObjectName;

	//이동방향
	float		_fAngleX;
	float		_fAngleY;

	float		_fDashTime;


	STATE*		_pCurrentState;
	STATE*		_arState[static_cast<const int>(PLAYER::PLAYER_STATE::MAX)];


	MOVE_DIRECTION			_eMoveDirection;
	CIRCLEEFFECT*		_pCirEffect;
	
	float		_fAttackDirAngle;

	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;

	//임시
	SKILL*		_pFireDash;
public:
	PLAYER();
	~PLAYER();

	//씬이 끝나면 다른 것이 저장 되야 할 수 있기에 필요
	void load();
	//씬이 끝나면 저장이 필요하다. 스킬은 무엇을 들고 있는지 망토는 무엇인지 등등의 정보를 저장한다.
	void save();
	//초기화
	void init();


	//자식들에서 재정의 필수
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;


private:
	void setEnumName();
	void setAnimation();

	const string addAniString(const string& strDir, const string& strAction);

	void addPlayerKeyAni(const string & strDir, const string & strAction, int nStartFrame,int nEndFrame, int nFPS, bool bIsLoop);

	//스킬마다 스킬 시전 시간을 가지고 그 시간이 지나면 애니메이션을 바꾸고 하자

	void settingPos();
	


public:
//state pattern용
//skill은 좀더 생각할 필요가 있다.
//스킬이 뭔지 알아야한다.

	void setState(PLAYER::PLAYER_STATE ePlayerState);
	void setDirection(PLAYER::DIRECTION eDirection);
	void settingAni();
	void setAction(PLAYER::ACTION eAction);
	void input();
	void initState();
public:
	void moveUp(float fSpeed);
	void moveDown(float fSpeed);
	void moveLeft(float fSpeed);
	void moveRight(float fSpeed);
	void moveUpLeft(float fSpeed);
	void moveUpRight(float fSpeed);
	void moveDownLeft(float fSpeed);
	void moveDownRight(float fSpeed);



	inline float getSpeed() { return _fSpeed; }
	void dash(float fOffset);
	void movePlayer();

	void setDirectionUp();
	void setDirectionDown();
	void setDirectionLeft();
	void setDirectionRight();

public:
	inline void setDashTime(float fDashTime) { _fDashTime = fDashTime; }
	inline float getDashTime() { return _fDashTime; }
	void addDashTime() { _fDashTime += TIMEMANAGER->getElapsedTime(); }

public:
	inline PLAYER::DIRECTION getDrection() { return _direction; }
	inline animation* getAni() { return _pAnimation; }



	void setLink(MAGICMGR* pMagicMgr, SKILL_EFFECT_MGR* pSkillEffectMgr);


	//임시
	SKILL*	getSkill() { return _pFireDash; }
};