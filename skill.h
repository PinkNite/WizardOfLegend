#pragma once
#include "stdafx.h"
#include "player.h"
#include "map.h"
class MAGICMGR;
class SKILL_EFFECT_MGR;
class PLAYER;

class SKILL
{
public:
	//스킬타입을 비트마스크로 담는다
	enum class SKILL_TYPE
	{
		NONE = 0x00,
		NORMAL = 0x01,
		DASH = 0x02,
		SPECIAL = 0x04,
		ULTIMATE = 0x08
	};

protected:
	MAGICMGR * _pMagicMgr;					
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;
	PLAYER*				_pPlayer;
	int					_nSkillType;		//스킬 타입이 담긴다.
	PLAYER::SKILL_NAME	_eSkillName;		//스킬 이름이 담긴다.
	MAP*				_pMap;

public:
	SKILL();
	virtual ~SKILL();

	virtual	void	init(PLAYER::SKILL_NAME eSkillName);
	virtual	void	update()		abstract;
	virtual	void	release()		abstract;
	virtual	void	render(HDC hdc)	abstract;
	virtual void	pushMagicKey(float fPosX, float fPosY);					//매직키를 누르면 발동
	virtual void	pullMagicKey(float fPosX = 0.0f, float fPosY = 0.0f);	//매직키를 때면 발동

public:
	void setMagicMgr(MAGICMGR* pMagicMgr);
	void setSkillEffectMgr(SKILL_EFFECT_MGR* pSkillEffectMgr);
	void setPlayer(PLAYER* pPlayer);
	void setMap(MAP* pMap);


	virtual int	getSkillType();
};
