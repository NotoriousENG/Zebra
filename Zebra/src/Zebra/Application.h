#pragma once

#include "Core.h"

namespace Zebra
{
	class ZEBRA_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}



