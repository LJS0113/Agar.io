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

		void SetX(float xVal) { x = xVal; }
		void SetY(float yVal) { y = yVal; }
		void SetColor(Vector4 colorVal) { mColor = colorVal; }
		void SetScale(float scaleVal) { scale = scaleVal; }

	private:
		eState mState;
		float x;
		float y;
		Vector4 mColor;
		float scale;
		graphics::ConstantBuffer* cellCB;
	};

}