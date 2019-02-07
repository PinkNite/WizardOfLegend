#pragma
#include "item.h"
class ITEMMANAGER
{
private:
	ITEM* _pItem;
public:
	ITEMMANAGER();
	~ITEMMANAGER();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};
