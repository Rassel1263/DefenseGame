#include "DXUT.h"
#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(D3DXVECTOR2 pos, int index) : Units(pos, index)
{
}

void EnemyUnit::Update(float deltaTime)
{
}

void EnemyUnit::Render()
{
	Units::Render();
}
