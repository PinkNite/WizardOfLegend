#include "stdafx.h"
#include "skillIcon.h"


SKILLICON::SKILLICON()
{
}

SKILLICON::~SKILLICON()
{
}

HRESULT SKILLICON::init(int x, int y)
{
	OBJECT::setImage(IMAGEMANAGER->addFrameImage("skillIcon", "resource/UI/skillIcon.bmp", 690, 690, 16, 16, true, RGB(255, 0, 255)));
	OBJECT::init(x, y, OBJECT::getImage()->getFrameWidth(), OBJECT::getImage()->getFrameHeight());
	setSkillIcon();
	return S_OK;
}

void SKILLICON::release()
{
}

void SKILLICON::update()
{
}

void SKILLICON::render(HDC hdc)
{
	OBJECT::getImage()->alphaFrameRender(hdc, OBJECT::getPosX(), OBJECT::getPosX(),,0,_alpha);
}

void SKILLICON::setSkillIcon()
{
	
	for (int i = 0; i < 10; i++)
	{
		switch (i)
		{
		case 0:
			_skillIcon.name = "Flame Strike";    //6
			_skillIcon.info = "Blast enemies away with plumes of flames!";
			_skillIcon.element = FIRE;
			_skillIcon.skillType = BASIC;
			_skillIcon.damage = 8;
			_skillIcon.damage2 = 10;
			_skillIcon.damage3 = 14;
			_skillIcon.damage4 = 18;
			_skillIcon.damage5 = NULL;
			_skillIcon.coolDown = 0;
			_skillIcon.knockBack = 5;
			_skillIcon.knockBack2 = 6;
			_skillIcon.knockBack3 = 12;
			_skillIcon.knockBack4 = 12;
			_skillIcon.duration = NULL;
			_skillIcon.platinum = 10;
			_skillIcon.gold = 100;
			_skillIcon.pool = 1;
			_skillIcon.frameX = 6 % 16;
			_skillIcon.frameY = 6 / 16;

			break;
		case 1:
		
			_skillIcon.name = "Flare Rush";    //6
			_skillIcon.info = "Rush forward and conjure a volley of accompanying flares!";
			_skillIcon.element = FIRE;
			_skillIcon.skillType = DASH;
			_skillIcon.damage = 10;
			_skillIcon.damage2 = 0;
			_skillIcon.damage3 = 0;
			_skillIcon.damage4 = 0;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 6;
			_skillIcon.knockBack = 20;
			_skillIcon.knockBack2 = 0;
			_skillIcon.knockBack3 = 0;
			_skillIcon.knockBack4 = 0;
			_skillIcon.duration = NULL;
			_skillIcon.platinum = 20;
			_skillIcon.gold = 125;
			_skillIcon.pool = 4;
			_skillIcon.frameX = 21 % 16;
			_skillIcon.frameY = 21 / 16;

			break;
		case 2:
				
			_skillIcon.name = "Magsphere";    //6
			_skillIcon.info = "Designed by Virtuoso David Gottsegen, this arcana allows you to pull all nearby projectiles into an orbit around you!";
			_skillIcon.element = LIGHTNING;
			_skillIcon.skillType = STANDARD;
			_skillIcon.damage = 0;
			_skillIcon.damage2 = 0;
			_skillIcon.damage3 = 0;
			_skillIcon.damage4 = 0;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 12;
			_skillIcon.knockBack = 0;
			_skillIcon.knockBack2 = 0;
			_skillIcon.knockBack3 = 0;
			_skillIcon.knockBack4 = 0;
			_skillIcon.duration = 5;
			_skillIcon.platinum = 12;
			_skillIcon.gold = 175;
			_skillIcon.pool = 2;
			_skillIcon.frameX = 105 % 16;
			_skillIcon.frameY = 105 / 16;

			break;
		case 3:

			_skillIcon.name = "Thundering Chain";    //6
			_skillIcon.info = "Generate a series of lightning strikes that shock foes!";
			_skillIcon.element = LIGHTNING;
			_skillIcon.skillType = STANDARD;
			_skillIcon.damage = 10;
			_skillIcon.damage2 = 0;
			_skillIcon.damage3 = 0;
			_skillIcon.damage4 = 0;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 6;
			_skillIcon.knockBack = 0;
			_skillIcon.knockBack2 = 0;
			_skillIcon.knockBack3 = 0;
			_skillIcon.knockBack4 = 0;
			_skillIcon.duration = 0;
			_skillIcon.platinum = 10;
			_skillIcon.gold = 125;
			_skillIcon.pool = 1;
			_skillIcon.frameX = 101 % 16;
			_skillIcon.frameY = 101 / 16;

			break;
		case 4:

			_skillIcon.name = "Stone Shot";    //6
			_skillIcon.info = "Rapidly fire stones!";
			_skillIcon.element = EARTH;
			_skillIcon.skillType = BASIC;
			_skillIcon.damage = 12;
			_skillIcon.damage2 = 12;
			_skillIcon.damage3 = 15;
			_skillIcon.damage4 = 15;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 0;
			_skillIcon.knockBack = 10;
			_skillIcon.knockBack2 = 10;
			_skillIcon.knockBack3 = 16;
			_skillIcon.knockBack4 = 16;
			_skillIcon.duration = 0;
			_skillIcon.platinum = 14;
			_skillIcon.gold = 100;
			_skillIcon.pool = 3;
			_skillIcon.frameX = 47 % 16;
			_skillIcon.frameY = 47 / 16;

			break;

		case 5:

			_skillIcon.name = "Glacial Cross";    //6
			_skillIcon.info = "Dash forward and conjure a colossal frozen fist to strike foes!";
			_skillIcon.element = WATER;
			_skillIcon.skillType = SIGNATURE;
			_skillIcon.damage = 50;
			_skillIcon.damage2 = 10;
			_skillIcon.damage3 = 30;
			_skillIcon.damage4 = 0;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 7;
			_skillIcon.knockBack = 70;
			_skillIcon.knockBack2 = 10;
			_skillIcon.knockBack3 = 5;
			_skillIcon.knockBack4 = 0;
			_skillIcon.duration = 0;
			_skillIcon.platinum = 17;
			_skillIcon.gold = 175;
			_skillIcon.pool = 3;
			_skillIcon.frameX = 36 % 16;
			_skillIcon.frameY = 36 / 16;

			break;
		case 6:

			_skillIcon.name = "Rebounding Icicles";    //6
			_skillIcon.info = "Conjure a series of icicles that cascade out and return to you!";
			_skillIcon.element = WATER;
			_skillIcon.skillType = SIGNATURE;
			_skillIcon.damage = 5;
			_skillIcon.damage2 = 7;
			_skillIcon.damage3 = 0;
			_skillIcon.damage4 = 0;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 5;
			_skillIcon.knockBack = 25;
			_skillIcon.knockBack2 = 0;
			_skillIcon.knockBack3 = 0;
			_skillIcon.knockBack4 = 0;
			_skillIcon.duration = 0;
			_skillIcon.platinum = 0;
			_skillIcon.gold = 150;
			_skillIcon.pool = 5;
			_skillIcon.frameX = 32 % 16;
			_skillIcon.frameY = 32 / 16;

			break;
		case 7:

			_skillIcon.name = "Shattering Strike";    //6
			_skillIcon.info = "Strike a boulder to shatter it into a ring of shrapnel!";
			_skillIcon.element = EARTH;
			_skillIcon.skillType = SIGNATURE;
			_skillIcon.damage = 25;
			_skillIcon.damage2 = 5;
			_skillIcon.damage3 = 5;
			_skillIcon.damage4 = 0;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 5;
			_skillIcon.knockBack = 10;
			_skillIcon.knockBack2 = 20;
			_skillIcon.knockBack3 = 0;
			_skillIcon.knockBack4 = 0;
			_skillIcon.duration = 0;
			_skillIcon.platinum = 75;
			_skillIcon.gold = 175;
			_skillIcon.pool = 3;
			_skillIcon.frameX = 41 % 16;
			_skillIcon.frameY = 41 / 16;

			break;
		case 8:
	
			_skillIcon.name = "Tearing Whirlwind";    //6
			_skillIcon.info = "Rapidly spin forward and pull nearby enemies into your wake!";
			_skillIcon.element = AIR;
			_skillIcon.skillType = STANDARD;
			_skillIcon.damage = 4;
			_skillIcon.damage2 = 5;
			_skillIcon.damage3 = 0;
			_skillIcon.damage4 = 0;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 5;
			_skillIcon.knockBack = -20;
			_skillIcon.knockBack2 = -22;
			_skillIcon.knockBack3 = 0;
			_skillIcon.knockBack4 = 0;
			_skillIcon.duration = 0;
			_skillIcon.platinum = 16;
			_skillIcon.gold = 150;
			_skillIcon.pool = 3;
			_skillIcon.frameX = 85 % 16;
			_skillIcon.frameY = 85 / 16;

			break;
		case 9:

			_skillIcon.name = "Terra Ring";    //6
			_skillIcon.info = "Pulverize the ground to summon cascading rings of earth spikes!";
			_skillIcon.element = EARTH;
			_skillIcon.skillType = SIGNATURE;
			_skillIcon.damage = 15;
			_skillIcon.damage2 = 50;
			_skillIcon.damage3 = 25;
			_skillIcon.damage4 = 0;
			_skillIcon.damage5 = 0;
			_skillIcon.coolDown = 5;
			_skillIcon.knockBack = 7;
			_skillIcon.knockBack2 = 12;
			_skillIcon.knockBack3 = 1;
			_skillIcon.knockBack4 = 0;
			_skillIcon.duration = 0;
			_skillIcon.platinum =75;
			_skillIcon.gold = 150;
			_skillIcon.pool = 5;
			_skillIcon.frameX = 42 % 16;
			_skillIcon.frameY = 42 / 16;

			break;
		}
		_vSkillIcon.push_back(_skillIcon);
		_mSkillIcon.insert(make_pair(_str, _vSkillIcon));

	}
}
