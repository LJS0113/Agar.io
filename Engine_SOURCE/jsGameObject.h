#pragma once
#include "jsEntity.h"
#include "jsComponent.h"
#include "jsRenderer.h"

namespace js
{
	class GameObject : public Entity
	{
	public:
		enum eState
		{
			Active,
			Paused,
			Dead,
		};

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void OnCollision();

		Vector4 GetPos() { return mPos; }
		float GetScale() { return mScale; }
		Vector2 GetSize() { return mSize; }

		GameObject* GetGameObject() { return this; }

	private:
		eState mState;
		//std::vector<Component*> mComponents;
		float x;
		float y;
		float mScale;
		Vector4 mPos;
		Vector2 mSize;
	};

}