#include "Asteroid.h"

class ExampleLayer : public Asteroid::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
	}

	void OnEvent(Asteroid::Event& event) override
	{
		if (event.GetEventType() == Asteroid::EventType::KeyPressed)
		{
			Asteroid::KeyPressedEvent& e = (Asteroid::KeyPressedEvent&)event;
			if (e.GetKeyCode() == AS_KEY_TAB)
				AS_TRACE("Tab key is pressed (event)!");
			AS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Asteroid::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Asteroid::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Asteroid::Application* Asteroid::CreateApplication()
{
	return new Sandbox();
}