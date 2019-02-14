#pragma once
#include "stdafx.h"
#include "skill.h"

class FIREDASH : public SKILL {
private:
	float	_fOffsetTime;
	float	_fTimer;
	bool	_bIsOk;
public:
	FIREDASH();
	~FIREDASH();

	virtual	void	init(PLAYER::SKILL_NAME eSkillName)			override;
	virtual	void	update()		override;
	virtual	void	release()		override;
	virtual	void	render(HDC hdc)	override;

};