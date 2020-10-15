#pragma once

#include "Core.h"

#include "Window.h"

#include "Asteroid/LayerStack.h"
#include "Asteroid/Events/Event.h"
#include "Asteroid/Events/ApplicationEvent.h"

#include "Asteroid/ImGui/ImGuiLayer.h"
#include "imgui.h"

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
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}
