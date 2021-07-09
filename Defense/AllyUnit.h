#pragma once
class AllyUnit : public Units
{
public:
	AllyUnit(D3DXVECTOR2 pos, int index);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

