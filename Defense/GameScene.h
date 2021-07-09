#pragma once

class GameScene : public Scene
{
public:
	Map* map = NULL;

	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

