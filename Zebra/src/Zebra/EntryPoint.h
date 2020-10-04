#pragma once

#ifdef ZB_PLATFORM_WINDOWS

extern Zebra::Application* Zebra::CreateApplication();

int main(int argc, char** argv)
{
	Zebra::Log::Init();
	ZB_CORE_WARN("Initialized Log!");
	int a = 5;
	ZB_INFO("Hello! Var={0}", a);

	auto* app = Zebra::CreateApplication();
	app->Run();
	delete app;
}

#endif