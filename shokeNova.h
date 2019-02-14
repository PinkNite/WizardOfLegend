#pragma once
#include "stdafx.h"
#include "skill.h"

class SHOKENOVA : public SKILL
{
private:


public:
	SHOKENOVA();
	~SHOKENOVA();


	virtual	void	init(PLAYER::SKILL_NAME eSkillName);
	virtual	void	update()		override;
	virtual	void	release()		override;
	virtual	void	render(HDC hdc)	override;
	virtual void	useMagic(float fPosX, float fPosY);		//스킬 하나 쓰는 애들 위해

};
