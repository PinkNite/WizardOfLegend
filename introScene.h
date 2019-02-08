#pragma once

#include "gameNode.h"
struct tagIntro
{
	float x, y;
	float gravity;
	int alpha;
	image* image;

};
class INTROSCENE:public gameNode
{
private:
	tagIntro _title;
	tagIntro _logo;
	tagIntro _99;
	tagIntro _introPeople;
	tagIntro _hello;

public:
	INTROSCENE();
	~INTROSCENE();
	HRESULT init();
	void release();
	void update();
	void render();
	void imageSetting();
};

