#include "DXUT.h"
#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
{
}

void EnemySpawner::SpawnEnemy(float deltaTime)
{
	timer += deltaTime;

	if (timer >= 2.0f)
	{
		timer = 0.0f;

		int y = rand() % 5 - 2 ;
		if (y != 0) y *= 216;

		EnemyUnit* enemy = NULL;
		nowScene->obm.AddObject(enemy = new EnemyUnit(D3DXVECTOR2(-1000, y), 0));
		enemyVecs.push_back(enemy);

	}
}
