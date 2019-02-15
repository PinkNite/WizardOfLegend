#pragma once
#include "object.h"
#include <map>
#include <vector>
enum SKILLTYPE
{
	BASIC,
	STANDARD,
	DASH,
	SIGNATURE
};
enum ELEMENT
{
	FIRE,
	AIR,
	CHOAS,
	WATER,
	EARTH,
	LIGHTNING
};
struct TAGSKILLICON
{
	const char* name;
	const char* info;
	ELEMENT element;//속성
	SKILLTYPE skillType;//스킬종류
	int damage;//데미지
	int damage2;
	int damage3;
	int damage4;
	int damage5;
	int coolDown;//쿨다운
	int knockBack;//넉백시간
	int knockBack2;
	int knockBack3;
	int knockBack4;
	int duration;//지속
	int platinum;
	int gold;
	int pool;
	int frameX;
	int frameY;

};
class SKILLICON:public OBJECT
{
private:
	vector<TAGSKILLICON> _vSkillIcon;
	vector<TAGSKILLICON>::iterator _viSkillIcon;
	map<string,vector<TAGSKILLICON>> _mSkillIcon;
	int _alpha;
	int _num;
	string _str;
	TAGSKILLICON _skillIcon;
	
public:
	SKILLICON();
	~SKILLICON();
	HRESULT init(int x, int y);
	void release();
	void update();
	void render(HDC hdc);
	void setSkillIcon();
public:
	int getAlpha() { return _alpha;}
	void setAlpha(int num) { _alpha = num; }
	void setNum(int num) { _num = num; }
	int getNum() { return _num; }
	vector<TAGSKILLICON> getVSkillIcon() { return _vSkillIcon; }
};

