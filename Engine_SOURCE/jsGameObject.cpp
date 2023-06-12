#include "jsGameObject.h"
#include "jsRenderer.h"
#include "jsGraphicDevice_DX11.h"
#include "jsInput.h"
#include "jsConstantBuffer.h"

namespace js
{
	using namespace renderer;
	GameObject::GameObject()
		: mState(eState::Active)
		, x(0.0f)
		, y(0.0f)
	{

	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
	}
	void GameObject::Update()
	{
		// 공의 움직임 구현
		if (Input::GetKey(eKeyCode::A))
		{
			x -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			x += 0.01f;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			y += 0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			y -= 0.01f;
		}
		Vertex ver = {};
		ver.pos = Vector4(x, y, 0.0f, 1.0f);
		ver.color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		constantBuffer->SetData(&ver);
		constantBuffer->Bind(eShaderStage::VS);
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}