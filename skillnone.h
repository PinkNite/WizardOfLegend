#pragma once
#include "stdafx.h"
#include "skill.h"

class NONESKILL : public SKILL 
{
private:


public:
	NONESKILL();
	~NONESKILL();

	virtual	void	update()		override;
	virtual	void	release()		override;
	virtual	void	render(HDC hdc)	override;
};