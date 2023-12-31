#pragma once
#include "jsEngine.h"
#include "jsGraphicDevice_DX11.h"
#include "jsMesh.h"
#include "jsShader.h"
#include "jsConstantBuffer.h"


using namespace js::math;
namespace renderer
{
	struct Vertex
	{
		Vector4 pos;
		Vector4 color;
	};

	extern Vertex vertexes[];
	extern js::Mesh* mesh;
	extern js::Shader* shader;
	extern js::graphics::ConstantBuffer* constantBuffer;

	void Initialize();
	void Release();

	void LoadBuffer();
	void LoadShader();
	void SetupState();
}