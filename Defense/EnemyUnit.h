#pragma once
class EnemyUnit : public Units
{
public: 
	float speed = 200.0f;

	EnemyUnit(D3DXVECTOR2 pos, int index);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnCollision2D(Collider2D& other) override;
};

