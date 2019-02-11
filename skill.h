#pragma once
#include "stdafx.h"

class SKILL abstract
{
public:
	virtual	void	init()			abstract;
	virtual	void	update()		abstract;
	virtual	void	release()		abstract;
	virtual void	render(HDC hdc)	abstract;
};