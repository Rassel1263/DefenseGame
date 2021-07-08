#include "DXUT.h"
#include "AllyUnit.h"

AllyUnit::AllyUnit(D3DXVECTOR2 pos) : Units(pos)
{
	
}

void AllyUnit::Update(float deltaTime)
{
}

void AllyUnit::Render()
{
	Units::Render();
}
