#include "DXUT.h"
#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(D3DXVECTOR2 pos) : Units(pos)
{
}

void EnemyUnit::Update(float deltaTime)
{
}

void EnemyUnit::Render()
{
	Units::Render();
}
