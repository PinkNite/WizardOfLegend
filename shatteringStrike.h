#pragma once

#include "stdafx.h"
#include "skill.h"

class SHATTERINGSTRIKE : public SKILL {

private:
	float	_fTimer;
	float	_fOffsetTimer;

	float	_fPosX;
	float	_fPosY;
	bool	_bIsUse;
public:
	SHATTERINGSTRIKE();
	~SHATTERINGSTRIKE();

	virtual	void	init(PLAYER::SKILL_NAME eSkillName);
	virtual	void	update()				override;
	virtual	void	release()				override;
	virtual	void	render(HDC hdc)			override;
	virtual void	pushMagicKey(float fPosX, float fPosY);		//스킬 하나 쓰는 애들 위해
	virtual void	pullMagicKey(float fPosX = 0.0f, float fPosY = 0.0f);

};