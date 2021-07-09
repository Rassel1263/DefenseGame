#include "DXUT.h"
#include "Map.h"

Map::Map()
{
	eGround.resize(5);
	eRi.resize(5);

	pGround.resize(5);
	pRi.resize(5);

	useGround.resize(5);

	int xSize = 3;

	for (int i = 0; i < 5; ++i)
	{
		eGround[i].LoadAll(L"Assets/Sprites/EGround.png");
		eRi[i].pos = D3DXVECTOR2(-360.0f, 216 * (i - 2));

		pGround[i].resize(xSize);
		useGround[i].resize(xSize);
		pRi[i].resize(xSize);

		for (int j = 0; j < xSize; ++j)
		{
			pGround[i][j].LoadAll(L"Assets/Sprites/pGround.png");
			useGround[i][j] = false;
			pRi[i][j].pos = D3DXVECTOR2(360 + 240 * j, 216 * (i - 2));
		}
	}

}

void Map::Update(float deltaTime)
{
	float mousePosX = Input::GetInstance().GetFixedMPos().x;
	float mousePosY = Input::GetInstance().GetFixedMPos().y;

	// 마우스 맨 아래 & 맨 위 방지 
	if (abs(mousePosY) >= 539)
		(mousePosY > 0) ? mousePosY -= 1 : mousePosY += 1;

	// 마우스 포지션을 인덱스 값으로
	int yIndex = round(mousePosY / 216) + 2;

	// 아군 진형
	if (mousePosX > 240)
	{
		int xIndex = round((mousePosX - 360) / 240);

		// 다른 진형으로 이동했을 때 전 진형에서 마지막으로 선택한 땅 해제
		if (pastGround)
			SetColor(*pastGround, D3DCOLOR_ARGB(255, 255, 255, 255));

		if (pastXIndex == xIndex && pastYIndex == yIndex) // 이전 땅과 선택한 땅이 같을 때(땅을 바꾸지 않았을 때)
			SetColor(pGround[yIndex][xIndex], D3DCOLOR_ARGB(255, 0, 0, 0)); // 땅을 선택(색을 바꿔줌)
		else // 이전 땅과 다른 땅을 선택했을 때(선택한 땅이 바뀌었을 때) 
			SetColor(pGround[pastYIndex][pastXIndex], D3DCOLOR_ARGB(255, 255, 255, 255)); // 이전 땅 선택 해제(색을 원래대로 돌려줌)

		// 선택한 땅이 사용중이지 않을 때
		if (Input::GetInstance().KeyDown(VK_LBUTTON) && !useGround[yIndex][xIndex])
		{
			useGround[yIndex][xIndex] = true; // 사용중인 땅으로 변환
			nowScene->obm.AddObject(new AllyUnit(D3DXVECTOR2(360 + 240 * xIndex, 216 * (yIndex - 2)), rand() % 2 + 1)); // 유닛 소환
		}

		pastGround = &pGround[yIndex][xIndex]; // 이전 땅을 기억
		pastXIndex = xIndex; // 이전 인덱스 기억
	}
	else // 적 진형
	{
		if (pastGround)
			SetColor(*pastGround, D3DCOLOR_ARGB(255, 255, 255, 255));

		if (pastYIndex == yIndex)
			SetColor(eGround[yIndex], D3DCOLOR_ARGB(255, 0, 0, 0));
		else
			SetColor(eGround[pastYIndex], D3DCOLOR_ARGB(255, 255, 255, 255));

		pastGround = &eGround[yIndex];
	}

	pastYIndex = yIndex;

}

void Map::Render()
{
	for (int i = 0; i < 5; ++i)
	{
		eGround[i].Render(eRi[i]);

		int xSize = pGround[i].size();
		for (int j = 0; j < xSize; ++j)
		{
			pGround[i][j].Render(pRi[i][j]);
		}
	}

}

void Map::SetColor(Sprite& spr, D3DXCOLOR color)
{
	spr.color = color;
}
