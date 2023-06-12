#include "jsCell.h"
#include "jsRenderer.h"


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
		Vector4 mPos(x, y, 0.0f, scale);
		cellCB->Create(sizeof(Vector4)*2);

		Vertex ver = {};
		ver.pos = mPos;
		ver.color = mColor;

		cellCB->SetData(&ver);
		cellCB->Bind(eShaderStage::VS);

		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}