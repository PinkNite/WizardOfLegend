#pragma once
#include "stdafx.h"

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
	MAGICMGR*		_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;
	PLAYER*			_pPlayer;
	int				_nSkillType;

public:
	SKILL();
	~SKILL();

	virtual	void	init()			abstract;
	virtual	void	update()		abstract;
	virtual	void	release()		abstract;
	virtual	void	render(HDC hdc)	abstract;


public:
	void setMagicMgr(MAGICMGR* pMagicMgr);
	void setSkillEffectMgr(SKILL_EFFECT_MGR* pSkillEffectMgr);
	void setPlayer(PLAYER* pPlayer);
};
