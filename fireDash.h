#pragma once
#include "stdafx.h"
#include "skill.h"
class FIREDASH : public SKILL {
private:
	
	RECT _arRect[8];



public:
	FIREDASH();
	~FIREDASH();

	virtual	void	init()			override;
	virtual	void	update()		override;
	virtual	void	release()		override;
	virtual void	render(HDC hdc)	override;
};