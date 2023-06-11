#pragma once
#include "jsEntity.h"
#include "jsGameObject.h"
#include "jsCell.h"

namespace js
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
		std::vector<GameObject*> mGameObjects;
		std::vector<Cell*> mCells;
		float mTime;
	};

}