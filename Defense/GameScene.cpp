#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	srand(time(NULL));

	ShaderManager::GetInstance().CreateEffect("Simple", L"SimpleShader.fx", 0);

	obm.AddObject(mouse = new Mouse());
	obm.AddObject(map = new Map());

}

void GameScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void GameScene::Render()
{
	Scene::Render();
}
