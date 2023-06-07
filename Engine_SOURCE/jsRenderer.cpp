#include "jsRenderer.h"
#include "jsInput.h"


namespace renderer
{
	Vertex vertexes[4] = {};

	// Input Layout(���� ����)
	ID3D11InputLayout* triangleLayout = nullptr;

	// vertexes�� cpu�� ����Ǿ� �ִ� �����̹Ƿ� �̰� gpu�� �������� ���۰� �ʿ���. �װ� ���ؽ� ����.
	// Vertext Buffer
	js::Mesh* mesh = nullptr;
	//ID3D11Buffer* triangleBuffer = nullptr;
	//ID3D11Buffer* triangleIdxBuffer = nullptr;
	ID3D11Buffer* triangleConstantBuffer = nullptr;

	// �����Ͻÿ� ���� �߸� �ƴ��� �𸣴� �������� ������ ��Ƴ��� ���� �������
	// error blob
	ID3DBlob* errorBlob = nullptr;

	// ���̴����� ó���� �������� ������� ��. ���ؽ� ���̴����� ó���� �������� ���ؽ����̴���ӿ� ������.
	// Vertex Shader Code -> binary code
	js::Shader* shader = nullptr;
	//ID3DBlob* triangleVSBlob = nullptr;

	//// ���޹޴� ������ �����ϴ°��� ���ؽ� ���̴�.(���� = ��ġ������ ������ �°� ��ȯ)
	//// blob���� �ڵ常 ��������� �� �ڵ带 �����Ű�°� �ٷ� ���ؽ� ���̴�.
	//// VertexShader
	//ID3D11VertexShader* triangleVSShader = nullptr;

	//// PixelShader code -> binary code
	//ID3DBlob* trianglePSBlob = nullptr;

	// PixelShader
	ID3D11PixelShader* trianglePSShader = nullptr;

	void SetupState()
	{

	}

	void LoadBuffer()
	{
		mesh = new js::Mesh();
		mesh->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes = {};
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);

		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);

		// Index Buffer
		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// Constant Buffer
		D3D11_BUFFER_DESC triangleCSDesc = {};
		triangleCSDesc.ByteWidth = sizeof(Vector4);
		triangleCSDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		triangleCSDesc.Usage = D3D11_USAGE_DYNAMIC;
		triangleCSDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		js::graphics::GetDevice()->CreateBuffer(&triangleConstantBuffer, &triangleCSDesc, nullptr);

		Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);
		js::graphics::GetDevice()->SetConstantBuffer(renderer::triangleConstantBuffer, &pos, sizeof(Vector4));
		js::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, renderer::triangleConstantBuffer);
	}

	void LoadShader()
	{
		//js::graphics::GetDevice()->CreateShader();

		shader = new js::Shader();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
	}

	void Initialize()
	{
		vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		SetupState();
		LoadBuffer();
		LoadShader();
	}
	void renderer::Release()
	{
		if (triangleLayout != nullptr)
			triangleLayout->Release();

		if (triangleConstantBuffer != nullptr)
			triangleConstantBuffer->Release();

		if (errorBlob != nullptr)
			errorBlob->Release();

		if (trianglePSShader != nullptr)
			trianglePSShader->Release();
	}
}