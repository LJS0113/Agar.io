#include "jsApplication.h"
#include "jsTime.h"
#include "jsInput.h"
#include "jsRenderer.h"

namespace js
{
	Application::Application()
		: graphicDevice(nullptr)
		, mHwnd(NULL)
		, mWidth(-1)
		, mHeight(-1)
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Initialize()
	{
		Time::Initialize();
		Input::Initialize();

		renderer::Initialize();

		mScene = new Scene();
		mScene->Initialize();
	}
	void Application::Update()
	{
		Time::Update();
		Input::Update();

		mScene->Update();
		mScene->Destroy();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		Time::Render();

		graphicDevice->Draw();
		mScene->Render();
		graphicDevice->Present();
	}
	void Application::SetWindow(HWND hwnd, UINT width, UINT height)
	{
		if (graphicDevice == nullptr)
		{
			mHwnd = hwnd;
			mWidth = width;
			mHeight = height;

			graphicDevice = std::make_unique<js::graphics::GraphicDevice_DX11>();
			js::graphics::GetDevice() = graphicDevice.get();
		}

		RECT rt = { 0, 0, (LONG)width , (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}
}