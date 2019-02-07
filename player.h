#pragma once

#include "object.h"
#include "stdafx.h"
#include "animation.h"
class PLAYER : public OBJECT
{
public:
	enum class DIRECTION
	{
		FORWARD = 0,
		RIGHT,
		LEFT,
		BACK,
		MAX
	};

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
	enum { WIZARD_SPRITE_WIDTH = 1344 };
	enum { WIZARD_SPRITE_HEIGHT = 1536 };
	enum { WIZARD_SPRITE_MAXFRAMEX = 14 };
	enum { WIZARD_SPRITE_MAXFRAMEY = 16 };

private:
	float _fMaxHealthPoint;			//최대 생명력
	float _fCurrentHealthPoint;		//현재 생명력
	float _fSpeed;					//속도
	float _fArmor;					//방어력
	float _fEvasion;				//회피율
	float _fCriticalHit;			//치명타율

	float	_fPosMovingX;				//움직이는 용 x
	float	_fPosMovingY;				//움직이는 용 y
	int		_nCollsionMovingWidth;	//움직임 충돌용 가로
	int		_nCollsionMovingHeight;	//움직임 충돌용 세로

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

	

};