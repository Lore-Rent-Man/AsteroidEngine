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
		AS_INFO("ExampleLayer::Update");

		if (Asteroid::Input::IsKeyPressed(AS_KEY_TAB))
		{
			AS_INFO("Tab key is pressed!");
		}
	}

	void OnEvent(Asteroid::Event& event) override
	{
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