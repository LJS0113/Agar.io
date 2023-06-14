#include "jsCell.h"
#include "jsRenderer.h"
#include "jsApplication.h"

extern js::Application application;

namespace js
{
	using namespace renderer;
	using namespace js::math;
	Cell::Cell()
		: mState(eState::Active)
		, x(0.0f)
		, y(0.0f)
		, mColor(Vector4(0.0f, 0.0f, 0.0f, 0.0f))
		, scale(0.0f)
		, cellCB(nullptr)
		, mPos(Vector4::Zero)
		, mSize(Vector2::Zero)
	{

	}
	Cell::~Cell()
	{
	}
	void Cell::Initialize()
	{

	}
	void Cell::Update()
	{
		
	}
	void Cell::LateUpdate()
	{
	}
	void Cell::Render()
	{
		cellCB = new ConstantBuffer(eCBType::Transform);
		Vector4 pos(x, y, 0.0f, scale);
		cellCB->Create(sizeof(Vector4)*2);
		Vertex ver = {};
		ver.pos = pos;
		ver.color = mColor;

		cellCB->SetData(&ver);
		cellCB->Bind(eShaderStage::VS);

		mPos.x = (vertexes[0].pos.x + x) * scale * application.GetWidth();
		mPos.y = (vertexes[0].pos.y + y) * scale * application.GetHeight();
		mSize.x = (vertexes[1].pos.x - vertexes[0].pos.x) * scale * application.GetWidth();
		mSize.y = (vertexes[1].pos.y - vertexes[2].pos.y) * scale * application.GetHeight(); 
		
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
	void Cell::OnCollision()
	{
		mState = Dead;
	}
	bool Cell::Intersect(GameObject* gameObj)
	{
		Vector4 playerPos = gameObj->GetPos();
		Vector4 cellPos = mPos;

		Vector2 playerSize = gameObj->GetSize();
		Vector2 cellSize = mSize;

		playerPos.x = playerPos.x + playerSize.x / 2.0f;
		playerPos.y = playerPos.y + playerSize.y / 2.0f;

		cellPos.x = cellPos.x + cellSize.x / 2.0f;
		cellPos.y = cellPos.y + cellSize.y / 2.0f;

		if (fabs(playerPos.x - cellPos.x) < (playerSize.x / 2.0f) + (cellSize.x / 2.0f)
			&& fabs(playerPos.y - cellPos.y) < (playerSize.y / 2.0f) + (cellSize.y / 2.0f))
		{
			return true;
		}

		return false;
	}
}