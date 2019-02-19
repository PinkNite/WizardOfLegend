#pragma once
#include "object.h"
#include "relics_Type.h"
#include "relics_Ring.h"
#include "relics_Cover.h"
#include "relics_Home.h"
#include "relics_Select.h"

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
	RELICS_TYPE* _pOffenceType;
	RELICS_TYPE* _pDefenceType;
	RELICS_TYPE* _pMISCType;
	RELICS_RING* _pRing[6];
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
};

