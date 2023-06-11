#include "jsScene.h"
#include "jsTime.h"
#include "jsRenderer.h"

namespace js
{
	using namespace renderer;
	Scene::Scene()
		: mTime(0.0f)
	{
	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		// ���⼭ �ʱ� ���� �ʵ����͸� ����������Ѵ�.
		GameObject* gameObject = new GameObject();
		mGameObjects.push_back(gameObject);
	}
	void Scene::Update()
	{
		mTime += Time::DeltaTime();
		if (mTime > 3.0f)
		{
			Cell* cell = new Cell();
			mCells.push_back(cell);

			mTime = 0.0f;
		}

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
		for (Cell* cellObj : mCells)
		{
			cellObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
	}
	void Scene::Render()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render();
		}

		for (Cell* cellObj : mCells)
		{
			cellObj->Render();
		}
	}
}