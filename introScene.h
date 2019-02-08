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
	void actionOff(float numA, int* alpha,int numB);//                     �ð�, ���ĺ���, ���İ�
	void actionOn(float numA, int* alpha,int numB);//                     �ð�, ���ĺ���, ���İ�
	void fontRender(HDC hdc, const char * str,const char* str2, int x, int y, int num, COLORREF color);
	//void actionOnOff(float numA, float numB, float numC, int* alpha, const char* keyName);//���̺��� ũ�� �񺸴� �����ð��� ���� ���İ��� 255 �ɶ�����
	//void actionOn(float numA, float numB, float numC, int* alpha, const char* keyName);//������ �ð��� �̹��� ��ü�ϰ� �����⸸��
	//void actionJump(float numA, float numB, float numC, int * alpha, const char * keyName, float* y, float* y2);//��Ʈ�� �����Ұ�
};

