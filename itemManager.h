#pragma once
#include "item.h"
#include "player.h"
#include "UI.h"
class ITEMMANAGER
{
private:
	PLAYER* _pPlayer;
	ITEM* _pItem[12];
	UI* _pUI;
public:
	ITEMMANAGER();
	~ITEMMANAGER();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

public:
	void setLinkUI(UI* u) { _pUI = u; }
	void setLinkPlayer(PLAYER* p) { _pPlayer = p; }
};
