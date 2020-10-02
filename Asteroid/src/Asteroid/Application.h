#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Asteroid/Events/ApplicationEvent.h"

#include "Asteroid/Layer.h"
#include "Asteroid/LayerStack.h"

#include "Window.h"

namespace Asteroid {

	class Application
	{
	public:
		ASTEROID_API Application();
		ASTEROID_API virtual ~Application();

		ASTEROID_API void Run();

		ASTEROID_API void OnEvent(Event& e);

		ASTEROID_API void PushLayer(Layer* layer);
		ASTEROID_API void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in client
	Application* CreateApplication();
}
