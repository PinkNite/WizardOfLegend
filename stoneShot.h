#pragma once
#include "stdafx.h"
#include "skill.h"

class STONESHOT : public SKILL
{
private:
	bool	_bIsOk;
	int		_nCount;
public:
	STONESHOT();
	~STONESHOT();

	virtual	void	init(PLAYER::SKILL_NAME eSkillName)			override;
	virtual	void	update()		override;
	virtual	void	release()		override;
	virtual	void	render(HDC hdc)	override;
	virtual void	pushMagicKey(float fPosX, float fPosY)		override;
	virtual void	pullMagicKey(float fPosX, float fPosY);


};