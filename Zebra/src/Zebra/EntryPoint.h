#pragma once

#ifdef ZB_PLATFORM_WINDOWS

extern Zebra::Application* Zebra::CreateApplication();

int main(int argc, char** argv)
{
	printf("Zebra Engine");
	auto app = Zebra::CreateApplication();
	app->Run();
	delete app;
}

#endif