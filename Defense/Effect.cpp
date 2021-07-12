#include "DXUT.h"
#include "Effect.h"

Effect::Effect(std::wstring filePath, D3DXVECTOR2 pos, bool loop)
{
	spr.LoadAll(L"Assets/Sprites/Units/Effect/" + filePath);
	spr.aniMaxTime = 0.05f;

	std::cout << "a" << std::endl;

	this->pos = pos;
	spr.bAniLoop = loop;
}

void Effect::Update(float deltaTime)
{
	if (!spr.bAnimation)
		destroy = true;

	spr.Update(deltaTime);
}

void Effect::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
