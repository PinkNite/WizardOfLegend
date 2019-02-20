#pragma once

#include "gameNode.h"
//#include "animation.h"
#include "opening.h"

class INTROSCENE :public gameNode
{
private:


	OPENING* _pOpening;
	image* _pMouse;


public:
	INTROSCENE();
	~INTROSCENE();
	HRESULT init();
	void release();
	void update();
	void render();
	void imageSetting();


};

