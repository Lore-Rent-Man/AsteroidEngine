#include "aspch.h"
#include "Application.h"

#include "Asteroid/Events/ApplicationEvent.h"
#include "Asteroid/Log.h"

namespace Asteroid {
	
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AS_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AS_TRACE(e);
		}
		while (true);
	}
}