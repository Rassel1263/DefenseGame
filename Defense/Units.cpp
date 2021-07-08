#include "DXUT.h"
#include "Units.h"

Units::Units(D3DXVECTOR2 pos)
{
	this->pos = pos;
	spr.LoadAll(L"Assets/Sprites/player.png");
}

void Units::Update(float deltaTime)
{
}

void Units::Render()
{
	ri.pos = pos;
	spr.Render(ri);
}
