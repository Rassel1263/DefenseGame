#pragma once
class EnemySpawner
{
public:
	std::vector<EnemyUnit*> enemyVecs;
	float timer = 0.0f;

	EnemySpawner();

	void SpawnEnemy(float deltaTime);
};

