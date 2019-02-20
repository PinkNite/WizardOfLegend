#include "stdafx.h" 
#include "rotateImgMaker.h"


rotateImgMaker::rotateImgMaker()
{
}


rotateImgMaker::~rotateImgMaker()
{
}

image * rotateImgMaker::MakeRotateImg(image* sourImg, int sourX, int sourY, int sourWid, int sourHei, float angle, bool trans, COLORREF transColor)
{
	
	if (sourImg == nullptr) return nullptr;

	//destImg ���� (DC��)
	image* destImg = new image;
	destImg->init((DWORD)0, sourWid, sourHei, trans, transColor);

	//	destImg�� sourImg�� �����ϰ�,
	//BitBlt(destImg->getMemDC(), 0, 0, sourWid, sourHei, sourImg->getMemDC(), 0, 0, BLACKNESS);		//	�����κп� ������ĥ��?

	//	destImg�� ������Ÿ �Ĺ�
	HBRUSH hBrush = CreateSolidBrush(transColor);
	HBRUSH oBrush = (HBRUSH)SelectObject(destImg->getMemDC(), hBrush);
	ExtFloodFill(destImg->getMemDC(), 1, 1, RGB(0, 0, 0), FLOODFILLSURFACE);		//	���� rgb�����ʿ�
	DeleteObject(hBrush);
	
	//	ȸ���� 1,2,3����Ʈ ���� - ������Ʈ ����̾���
	POINT rPoint[3];
	int dist = sqrt((sourWid / 2) * (sourWid / 2) + (sourHei / 2) * (sourHei / 2));
	float baseAngle[3];
	baseAngle[0] = PI - atanf(((float)sourHei / 2) / ((float)sourWid / 2));
	baseAngle[1] = atanf(((float)sourHei / 2) / ((float)sourWid / 2));
	baseAngle[2] = PI + atanf(((float)sourHei / 2) / ((float)sourWid / 2));

	for (int i = 0; i < 3; ++i)
	{
		rPoint[i].x = (sourWid / 2 + cosf(baseAngle[i] + angle) * dist);
		rPoint[i].y = (sourHei / 2 + -sinf(baseAngle[i] + angle)* dist);
	}


	//  destImg plgblt �� ȸ����Ű��,
	PlgBlt(destImg->getMemDC(), rPoint, sourImg->getMemDC(),
		0,
		0,
		sourWid,
		sourHei,
		NULL, 0, 0);

	//	return destImg �Ѵ�.

	return destImg;
}
