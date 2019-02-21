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
	//��ųŸ���� ��Ʈ����ũ�� ��´�
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
	int					_nSkillType;		//��ų Ÿ���� ����.
	PLAYER::SKILL_NAME	_eSkillName;		//��ų �̸��� ����.
	MAP*				_pMap;

public:
	SKILL();
	virtual ~SKILL();

	virtual	void	init(PLAYER::SKILL_NAME eSkillName);
	virtual	void	update()		abstract;
	virtual	void	release()		abstract;
	virtual	void	render(HDC hdc)	abstract;
	virtual void	pushMagicKey(float fPosX, float fPosY);					//����Ű�� ������ �ߵ�
	virtual void	pullMagicKey(float fPosX = 0.0f, float fPosY = 0.0f);	//����Ű�� ���� �ߵ�

public:
	void setMagicMgr(MAGICMGR* pMagicMgr);
	void setSkillEffectMgr(SKILL_EFFECT_MGR* pSkillEffectMgr);
	void setPlayer(PLAYER* pPlayer);
	void setMap(MAP* pMap);


	virtual int	getSkillType();
};
