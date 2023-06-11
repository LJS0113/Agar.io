#include "jsCell.h"
#include "jsRenderer.h"


namespace js
{
	using namespace renderer;
	Cell::Cell()
		: mState(eState::Active)
		, x(0.0f)
		, y(0.0f)
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
		srand((unsigned)time(NULL));
		x = ((float)(std::rand() % 2000) - 1000) / 1000;
		y = ((float)(std::rand() % 2000) - 1000) / 1000;
	}
	void Cell::LateUpdate()
	{
	}
	void Cell::Render()
	{
		cellCB = new ConstantBuffer(eCBType::Transform);

		Vector4 pos(x, y, 0.0f, 1.0f);
		cellCB->Create(sizeof(Vector4));
		cellCB->SetData(&pos);
		cellCB->Bind(eShaderStage::VS);

		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}