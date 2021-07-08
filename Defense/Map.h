#pragma once

class Map : public Object
{
public:
	std::vector<Sprite> eGround;
	std::vector<RenderInfo> eRi;

	std::vector<std::vector<Sprite>> pGround;
	std::vector<std::vector<RenderInfo>> pRi;

	int pastXIndex = 0;
	int pastYIndex = 0;

	Map();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	void SetColor(Sprite& spr, D3DXCOLOR color);
};

