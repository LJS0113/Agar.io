#pragma once
#include "jsGameObject.h"
#include "jsConstantBuffer.h"

namespace js
{
	using namespace js::math;
	class Cell : public GameObject
	{
	public:
		Cell();
		~Cell();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollision() override;

		void SetX(float xVal) { x = xVal; }
		void SetY(float yVal) { y = yVal; }
		void SetColor(Vector4 colorVal) { mColor = colorVal; }
		void SetScale(float scaleVal) { scale = scaleVal; }

		bool Intersect(GameObject* gameObj);
		Vector4 GetPos() { return mPos; }
		Vector2 GetSize() { return mSize; }

		eState GetState() { return mState; }

	private:
		eState mState;
		float x;
		float y;
		Vector4 mColor;
		Vector4 mPos;
		Vector2 mSize;
		float scale;
		graphics::ConstantBuffer* cellCB;
	};

}