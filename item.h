#pragma once
#include <map>
#include <vector>
#include "object.h"
#include "itemWhite.h"

enum TYPE
{
	OFFENSE,
	DEFENSE,
	CURSED,
	MISC,
	DOCTOR
};
struct TAGITEM
{
	TYPE type;
	const char* name;
	const char* info;
	int costA;
	int costB;
	int pool;
	int frameX;
	int frameY;
	int isDrop;
};
class ITEM :public OBJECT
{
private:
	ITEMWHITE* _pItemWhite;

	vector<TAGITEM> _vItem;
	vector<TAGITEM>::iterator _viItem;
	map<int, vector<TAGITEM>> _mItem;
	int _num;
	image* _pImage;
	int _x, _y;
	int _alpha;
	bool _isDrop;
public:
	ITEM();
	~ITEM();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void fontRender(HDC hdc, const char * str, const char* str2, int x, int y, int num, COLORREF color);//hdc, ³»¿ë, ±Û¾¾Ã¼,ÁÂÇ¥,ÁÂÇ¥,±Û¾¾ Å©±â, »ö±ò
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void setNum(int num) { _num = num; }
	int getNum() { return _num; }
public:
	//°ÙÀ¸·Î ³Ñ°Ü¾ßµÊ
	bool getIsDrop() { return _isDrop; }
	void setIsDrop(bool num) { _isDrop = num; }
	vector<TAGITEM> getVItem() { return _vItem; }
	map<int, vector<TAGITEM>> getMItem() { return _mItem; }

	void setVItemFrameX(int arrNum, int x) { _vItem[arrNum].frameX = x; }
	void setVItemFrameY(int arrNum, int y) { _vItem[arrNum].frameY = y; }

	void setAlpha(int alpha) { _alpha = alpha; }
	bool getItemWhiteAction() { return _pItemWhite->getIsAction(); }
	void setItemWhiteAction(bool s) { _pItemWhite->setIsAction(s); }

};
