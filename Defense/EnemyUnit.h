#pragma once
class EnemyUnit : public Units
{
public: 
	EnemyUnit(D3DXVECTOR2 pos);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

