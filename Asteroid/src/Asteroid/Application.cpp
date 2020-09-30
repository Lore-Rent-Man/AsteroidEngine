#include "aspch.h"
#include "Application.h"

#include "Asteroid/Events/ApplicationEvent.h"
#include "Asteroid/Log.h"

namespace Asteroid {
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_Window->OnUpdate();
		};
	}
} 