#pragma once
#include <Zebra.h>

class Sandbox : public Zebra::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		
	}
};

Zebra::Application* Zebra::CreateApplication()
{
	return new Sandbox();
}