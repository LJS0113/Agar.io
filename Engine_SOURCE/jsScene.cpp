#include "jsScene.h"
#include "jsTime.h"
#include "jsRenderer.h"

namespace js
{
	using namespace js::math;
	using namespace renderer;
	Scene::Scene()
		: mTime(0.0f)
		, mRandom(0.0f)
		, gameObject(nullptr)
		, x(0.0f)
		, y(0.0f)
		, scale(0.0f)
		, mColor(Vector4(0.0f, 0.0f, 0.0f, 0.0f))
	{

	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		// 여기서 초기 게임 맵데이터를 세팅해줘야한다.
		gameObject = new GameObject();
		mGameObjects.push_back(gameObject);
	}
	void Scene::Update()
	{
		srand((unsigned)time(NULL));
		mRandom = (float)(std::rand() % 5 + 2);
		mTime += Time::DeltaTime();
		if (mTime > mRandom)
		{
			Cell* cell = new Cell();
			mCells.push_back(cell);

			x = ((float)(std::rand() % 2000) - 1000) / 1000;
			y = ((float)(std::rand() % 2000) - 1000) / 1000;
			cell->SetX(x);
			cell->SetY(y);

			Vector4 color(((float)(std::rand() % 1000)) / 1000
				, ((float)(std::rand() % 1000)) / 1000
				, ((float)(std::rand() % 1000)) / 1000, 1.0f);
			cell->SetColor(color);

			scale = ((float)(std::rand() % 10)/10);
			cell->SetScale(scale);

			mTime = 0.0f;
		}

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
		for (Cell* cellObj : mCells)
		{
			cellObj->Update();
			if (cellObj->Intersect(gameObject))
			{
				gameObject->OnCollision();
				cellObj->OnCollision();
			}
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
	void Scene::Destroy()
	{
		std::vector<Cell*> deleteCells = {};
		for (std::vector<Cell*>::iterator iter = mCells.begin()
			; iter!= mCells.end();)
		{
			if ((*iter)->GetState() == GameObject::eState::Dead)
			{
				deleteCells.push_back((*iter));
				iter = mCells.erase(iter);
			}
			else
			{
				iter++;
			}
		}

		for (Cell* deathObj : deleteCells)
		{
			delete deathObj;
			deathObj = nullptr;
		}
	}
}