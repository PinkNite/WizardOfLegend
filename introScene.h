#pragma once

#include "gameNode.h"
//#include "animation.h"
#define GRAVITY 30
struct tagIntro
{
	float x, y;
	int alpha;
	image* image;
	int currentX;
	int currentY;

};
class INTROSCENE:public gameNode
{
private:
	tagIntro _title;
	tagIntro _logo;
	tagIntro _99;
	tagIntro _introPeople;
	tagIntro _hello;
	int _fontX, _arrFontY[8];
	float _angle;
	float _speed;

	
	float _jumpPower;
	float _time;
	float _timer;
	int _count;
	int _end;
	float _gravity;
	int _jumpCount;
	/*animation* _pAni;*/
	

public:
	INTROSCENE();
	~INTROSCENE();
	HRESULT init();
	void release();
	void update();
	void render();
	void imageSetting();
	void actionOff(float numA,float numB, int* alpha,int numC);//                     시간, 알파변수, 알파값
	void actionOn(float numA,float numB, int* alpha,int numC);//                     시간, 알파변수, 알파값
	void actionJump(float numA, float numB,  float* y, float* y2);
	void fontRender(HDC hdc, const char * str,const char* str2, int x, int y, int num, COLORREF color);
	void draw();
	

};

