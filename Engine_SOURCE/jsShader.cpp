#include "jsShader.h"

namespace js
{
	Shader::Shader()
		: mInputLayout(nullptr)
		, mTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
	{
	}
	Shader::~Shader()
	{
		mInputLayout->Release();
	}
	HRESULT Shader::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	bool Shader::Create(const eShaderStage stage, const std::wstring& fileName, const std::string& funcName)
	{
		std::filesystem::path shaderPath = std::filesystem::current_path().parent_path();
		shaderPath += L"\\Shader_SOURCE\\";

		std::filesystem::path fullpath(shaderPath.c_str());
		fullpath += fileName;

		ID3DBlob* errorblob = nullptr;

		if (stage == eShaderStage::VS)
		{
			GetDevice()->CompileFromFile(fullpath, funcName, "vs_5_0", mVSBlob.GetAddressOf());
			GetDevice()->CreateVertexShader(mVSBlob->GetBufferPointer(), mVSBlob->GetBufferSize(), mVS.GetAddressOf());
		}
		else if (stage == eShaderStage::PS)
		{
			GetDevice()->CompileFromFile(fullpath, funcName, "ps_5_0", mPSBlob.GetAddressOf());
			GetDevice()->CreatePixelShader(mPSBlob->GetBufferPointer(), mPSBlob->GetBufferSize(), mPS.GetAddressOf());
		}

		return true;
	}
	void Shader::Binds()
	{
		GetDevice()->BindPrimitiveTopology(mTopology);
		GetDevice()->BindInputLayout(mInputLayout);

		GetDevice()->BindVertexShader(mVS.Get());
		GetDevice()->BindPixelShader(mPS.Get());
	}
}