#pragma once
#include "stdafx.h"
#include "object.h"
#include "camera.h"

class STONESTATUE : public OBJECT {
private:
	CAMERA * _pCamera;

public:
	STONESTATUE();
	~STONESTATUE();


	void init(float fLeft, float fRight,int nWidth,int nHeight,image* pImage);
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

	void setLink(CAMERA* pCamera) { _pCamera = pCamera; }
};