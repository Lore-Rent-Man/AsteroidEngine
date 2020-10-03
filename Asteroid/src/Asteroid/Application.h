#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Asteroid/Events/ApplicationEvent.h"

#include "Asteroid/Layer.h"
#include "Asteroid/LayerStack.h"

#include "Window.h"

namespace Asteroid {

	class ASTEROID_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow();

		static Application& Get();
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
