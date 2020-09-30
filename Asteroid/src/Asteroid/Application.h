#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "Window.h"

namespace Asteroid {

	class ASTEROID_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in client
	Application* CreateApplication();
}
