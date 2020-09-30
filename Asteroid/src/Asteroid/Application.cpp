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
			m_Window->OnUpdate();
		};
	}
}