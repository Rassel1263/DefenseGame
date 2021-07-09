#include "DXUT.h"
#include "Units.h"

Units::Units(D3DXVECTOR2 pos, int index)
{
	this->pos = pos;
	this->unitIndex = index;
}

void Units::Update(float deltaTime)
{
	Object::Update(deltaTime);
}

void Units::Render()
{
	ri.pos = pos;
	spr.Render(ri);

	Object::Render();
}
