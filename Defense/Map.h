#pragma once

class Map : public Object
{
public:
	std::vector<Sprite> eGround;
	std::vector<RenderInfo> ri;

	Map();

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

