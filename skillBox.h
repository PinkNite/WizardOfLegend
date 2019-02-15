#pragma once
#include "object.h"
enum SKILLUSE
{
	USE,
	UN_USE
	//�׽�Ʈ�� �̳ѹ� ����� ����� ���� 
	//�÷��̾ų��� �޾ƿ������� �� �̳ѹ���
};

struct TAGPOLY //�ٰ��� ����ü
{
	float angle[4];
	POINT pos[4];
	SKILLUSE isUse;
};
class SKILLBOX:public OBJECT
{
private:
	int _frameX;
	int _x, _y;
	int _alpha;

	//��Ÿ�ӿ�
	TAGPOLY _poly[6];
	int _testX, _testY;
	RECT _rc;
	//�׽�Ʈ��
public:
	SKILLBOX();
	~SKILLBOX();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void coolDownSetting();
	void coolDownUpdate();
	void coolDownRender(HDC hdc);
public:
	void setFrameX(int num) { _frameX = num; }
	void setAlpha(int num) { _alpha = num; }
	int getAlpha() { return _alpha; }
};

