#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "glad/glad.h"
#include "glfw/glfw3.h"

namespace Asteroid {

	class ASTEROID_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}
