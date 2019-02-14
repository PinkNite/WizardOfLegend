#pragma once
#include "stdafx.h"
#include "player.h"

class MAGICMGR;
class SKILL_EFFECT_MGR;
class PLAYER;

class SKILL
{
public:
	enum class SKILL_TYPE
	{
		NONE = 0x00,
		NORMAL = 0x01,
		DASH = 0x02,
		SPECIAL = 0x04,
		ULTIMATE = 0x08
	};

protected:
	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;
	PLAYER*				_pPlayer;
	int					_nSkillType;
	PLAYER::SKILL_NAME	_eSkillName;
public:
	SKILL();
	virtual ~SKILL();

	virtual	void	init(PLAYER::SKILL_NAME eSkillName);
	virtual	void	update()		abstract;
	virtual	void	release()		abstract;
	virtual	void	render(HDC hdc)	abstract;
	virtual void	useMagic(float fPosX,float fPosY);		//스킬 하나 쓰는 애들 위해

public:
	void setMagicMgr(MAGICMGR* pMagicMgr);
	void setSkillEffectMgr(SKILL_EFFECT_MGR* pSkillEffectMgr);
	void setPlayer(PLAYER* pPlayer);


};
