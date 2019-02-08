#pragma once

#include "gameNode.h"
#define GRAVITY 30
struct tagIntro
{
	float x, y;
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
	int _fontX, _arrFontY[8];
	float _angle;
	float _speed;

	image* _pImage;
	float _jumpPower;
	float _time;
	

public:
	INTROSCENE();
	~INTROSCENE();
	HRESULT init();
	void release();
	void update();
	void render();
	void imageSetting();
	void actionOff(float numA, int* alpha,int numB);//                     시간, 알파변수, 알파값
	void actionOn(float numA, int* alpha,int numB);//                     시간, 알파변수, 알파값
	void fontRender(HDC hdc, const char * str,const char* str2, int x, int y, int num, COLORREF color);
	//void actionOnOff(float numA, float numB, float numC, int* alpha, const char* keyName);//에이보다 크고 비보다 작은시가넹 나옴 알파값이 255 될때까지
	//void actionOn(float numA, float numB, float numC, int* alpha, const char* keyName);//정해진 시간에 이미지 교체하고 나오기만함
	//void actionJump(float numA, float numB, float numC, int * alpha, const char * keyName, float* y, float* y2);//인트로 점프할것
};

