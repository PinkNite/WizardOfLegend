#pragma
#include <map>
#include <vector>
#include "object.h"
enum TYPE
{
	OFFENSE,
	DEFENSE,
	CURSED,
	MISC,
	DOCTOR
};
struct tagItem
{
	TYPE type;
	const char* name;
	const char* info;
	int costA;
	int costB;
	int pool;
	int frameX;
	int frameY;
};
class ITEM:public OBJECT
{
private:
	vector<tagItem> _vItem;
	vector<tagItem>::iterator _viItem;
	map<int, vector<tagItem>> _mItem;
	int _num;
	image* _pImage;
public:
	ITEM();
	~ITEM();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void fontRender(HDC hdc, const char * str, int x, int y, int num, COLORREF color);
};
