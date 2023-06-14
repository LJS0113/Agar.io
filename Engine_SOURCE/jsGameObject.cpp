#include "jsGameObject.h"
#include "jsRenderer.h"
#include "jsGraphicDevice_DX11.h"
#include "jsInput.h"
#include "jsConstantBuffer.h"
#include "jsApplication.h"

extern js::Application application;

namespace js
{
	using namespace renderer;
	GameObject::GameObject()
		: mState(eState::Active)
		, x(0.0f)
		, y(0.0f)
		, mPos(Vector4::Zero)
		, mSize(Vector2::Zero)
		, mScale(1.0f)
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
			x -= 0.0001f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			x += 0.0001f;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			y += 0.0001f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			y -= 0.0001f;
		}

		Vertex ver = {};
		ver.pos = Vector4(x, y, 0.0f, mScale);
		ver.color = Vector4(1.0f, 1.0f, 1.0f, 1.0f); 
		constantBuffer->SetData(&ver);
		constantBuffer->Bind(eShaderStage::VS);

		mPos.x = (vertexes[0].pos.x + x) * mScale * application.GetWidth();
		mPos.y = (vertexes[0].pos.y + y) * mScale * application.GetHeight();
		
		mSize.x = (vertexes[1].pos.x - vertexes[0].pos.x) * mScale * application.GetWidth();
		mSize.y = (vertexes[1].pos.y - vertexes[2].pos.y) * mScale * application.GetHeight();

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
	void GameObject::OnCollision()
	{
		mScale += 0.5f;
	}
}