#pragma once
#include "stdafx.h"
#include "skill.h"

class FIRESTRIKE: public SKILL
{
private:
	bool	_bIsOk;
	int		_nCount;
public:
	FIRESTRIKE();
	~FIRESTRIKE();

	virtual	void	init(PLAYER::SKILL_NAME eSkillName)			override;
	virtual	void	update()		override;
	virtual	void	release()		override;
	virtual	void	render(HDC hdc)	override;
	virtual void	useMagic(float fPosX, float fPosY)		override;
	virtual void	keyUp();

	
};