#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(int x, int y, int width, int height)
{
	_x = (float)x;
	_y = (float)y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", (float)x, (float)y, width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp", (float)x, (float)y, width, height, true, RGB(255, 0, 255));

	//���α׷��� �� �̹����� ũ�Ⱑ ����ũ�Ⱑ �ȴ�.
	_width = (float)_progressBarBottom->GetWidth();

	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	_rcProgress = RectMakeCenter((int)_x, (int)_y, _progressBarTop->GetWidth(), _progressBarTop->GetHeight());
}

void progressBar::render()
{
	//������ �׷��ִ� ���� ������ �޴´�. �׷����� ������� ������ ���´�
	IMAGEMANAGER->render("backBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->GetWidth() / 2,
		(int)_y + _progressBarBottom->GetHeight() / 2, 0, 0,
		_progressBarBottom->GetWidth(), _progressBarBottom->GetHeight());

	//�տ� �׷����� �������� ����ũ�⸦ �����Ѵ�.
	IMAGEMANAGER->render("frontBar", getMemDC(),
		_rcProgress.left + _progressBarBottom->GetWidth() / 2,
		(int)_y + _progressBarBottom->GetHeight() / 2, 0, 0,
		(int)_width, _progressBarBottom->GetHeight());



}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	//��ġ�� ������ ������ش�.
	_width = (currentGauge / maxGauge) * _progressBarBottom->GetWidth();
}
