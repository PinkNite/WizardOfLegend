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

	//destImg 생성 (DC도)
	image* destImg = new image;
	destImg->init((DWORD)0, sourWid, sourHei, trans, transColor);

	//	destImg에 sourImg를 복사하고,
	//BitBlt(destImg->getMemDC(), 0, 0, sourWid, sourHei, sourImg->getMemDC(), 0, 0, BLACKNESS);		//	남은부분에 검정색칠함?

	//	destImg에 마젠ㄴ타 쳐박
	HBRUSH hBrush = CreateSolidBrush(transColor);
	HBRUSH oBrush = (HBRUSH)SelectObject(destImg->getMemDC(), hBrush);
	ExtFloodFill(destImg->getMemDC(), 1, 1, RGB(0, 0, 0), FLOODFILLSURFACE);		//	여기 rgb조사필요
	DeleteObject(hBrush);
	
	//	회전할 1,2,3포인트 설정 - 알포인트 개재미없음
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


	//  destImg plgblt 로 회전시키고,
	PlgBlt(destImg->getMemDC(), rPoint, sourImg->getMemDC(),
		0,
		0,
		sourWid,
		sourHei,
		NULL, 0, 0);

	//	return destImg 한다.

	return destImg;
}
