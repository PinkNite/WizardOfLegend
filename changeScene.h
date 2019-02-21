#pragma once
#include "player.h"
class CHANGESCENE
{
private:
	PLAYER* _pPlayer;
public:

	CHANGESCENE();
	~CHANGESCENE();
	HRESULT init();
	void update();
	void release();
	void render(HDC hdc);
public:

	void setLinkPlayer(PLAYER* p) { _pPlayer = p; }
	
};

