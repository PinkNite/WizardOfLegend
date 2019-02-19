#pragma once
#include "menu.h"
#define GRAVITY 30
#define FONTSIZE 20

class OPENING
{
private:
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
		RECT rc;

	};
	TAGINTRO _title;
	TAGINTRO _logo;
	TAGINTRO _99;
	TAGINTRO _introPeople;
	TAGINTRO _hello;
	
	int _fontX, _arrFontY[8];//이건 어디에 쓰이노
	float _angle;
	float _speed;


	float _jumpPower;
	float _time;
	float _timer;
	int _count;
	int _end;
	float _gravity;
	int _jumpCount;
	

	bool _isStart;
	float _saveTime;

	MENU* _pMenu;

	int test;
public:
	OPENING();
	~OPENING();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void setImage();
	void helloManMove();
	void openingMove();
	void fontMove(HDC hdc);

	///////////////////////////////////////////////////인트로//////////////////
	void actionOff(float numA, float numB, int* alpha, int numC);//                     시간, 알파변수, 알파값
	void actionOn(float numA, float numB, int* alpha, int numC);//                     시간, 알파변수, 알파값
	void actionJump(float numA, float numB, float* y, float* y2);//로고 점프용 함수
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);//폰트 렌더할 함수
	void draw(HDC hdc);//이미지 애니메이션
	bool isCollision(int x, int y, int x2, int y2);//충돌 함수
	

};

class opening
{
public:
	opening();
	~opening();
};

