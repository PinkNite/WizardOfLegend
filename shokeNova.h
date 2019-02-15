#pragma once
#include "stdafx.h"
#include "skill.h"

class SHOKENOVA : public SKILL
{
private:
	bool	_bIsKeyDown;
	float	_fTimer;
	int		_nCount;

	float	_fPosX;
	float	_fPosY;
public:
	SHOKENOVA();
	~SHOKENOVA();


	virtual	void	init(PLAYER::SKILL_NAME eSkillName);
	virtual	void	update()		override;
	virtual	void	release()		override;
	virtual	void	render(HDC hdc)	override;
	virtual void	pushMagicKey(float fPosX, float fPosY);		//��ų �ϳ� ���� �ֵ� ����
	virtual void	pullMagicKey(float fPosX, float fPosY);

};
