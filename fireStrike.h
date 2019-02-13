#pragma once
#include "stdafx.h"
#include "skill.h"

class FIRESTRIKE: public SKILL
{
private:


public:
	FIRESTRIKE();
	~FIRESTRIKE();

	virtual	void	init()			override;
	virtual	void	update()		override;
	virtual	void	release()		override;
	virtual	void	render(HDC hdc)	override;
	virtual void	useMagic(float fPosX, float fPosY)		override;

	
};