#pragma once
#include "jsEntity.h"
#include "jsGameObject.h"
#include "jsCell.h"

namespace js
{
	using namespace js::math;
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void Destroy();

	private:
		std::vector<GameObject*> mGameObjects;
		std::vector<Cell*> mCells;
		GameObject* gameObject;
		float mTime;
		float mRandom;
		float x;
		float y;
		float scale;
		Vector4 mColor;
	};

}