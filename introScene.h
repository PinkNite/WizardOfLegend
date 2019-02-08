#pragma once

#include "gameNode.h"
//#include "animation.h"
#define GRAVITY 30
#define FONTSIZE 20
struct TAGINTRO
{
	float x, y;
	int alpha;
	image* image;
	int currentX;
	int currentY;
	int r, g, b;
	int count;
	int size;
	bool isSelect;
	float speed;

};
class INTROSCENE:public gameNode
{
private:
	TAGINTRO _title;
	TAGINTRO _logo;
	TAGINTRO _99;
	TAGINTRO _introPeople;
	TAGINTRO _hello;
	
	image* _pMouse;
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
	TAGINTRO _pressButton;
	TAGINTRO _singlePlayer;
	TAGINTRO _credit;
	TAGINTRO _option;
	TAGINTRO _mapEditor;
	TAGINTRO _quit;
	/*animation* _pAni;*/
	bool _isStart;

	int test;

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
	bool isCollision(int x, int y, int x2, int y2);
	void buttonClick();
};

