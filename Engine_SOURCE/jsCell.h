#pragma once
#include "jsGameObject.h"
#include "jsConstantBuffer.h"

namespace js
{
	class Cell : public GameObject
	{
	public:
		Cell();
		~Cell();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetX(float xval) { x = xval; }
		void SetY(float yval) { y = yval; }


	private:
		eState mState;
		float x;
		float y;
		graphics::ConstantBuffer* cellCB;
	};

}