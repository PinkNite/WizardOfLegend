#pragma once
#include "object.h"
#include "relics_Cover.h"
#include "relics_Home.h"
#include "relics_Select.h"
#include "button.h"

class RELICS :public OBJECT
{
private:
	enum RINGNAME
	{
		LEFT_1,
		LEFT_2,
		LEFT_3,
		RIGHT_1,
		RIGHT_2,
		RIGHT_3
	};
	enum COVERNAME
	{
		OFFENCE,
		DEFENCE,
		MISC
	};
	enum SELECTNAME
	{
		WHITE,
		BLACK
	};
	
	button* _pButton[3];
	POINT _point1;
	POINT _point2;

	RELICS_COVER* _pCover[3];
	RELICS_HOME* _pHome;
	RELICS_SELECT* _pSelect[2];
public:
	RELICS();
	~RELICS();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
public:
	void animaitionStart1();
	void animaitionStart2();
	void animaitionStart3();
};

