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
	}

	void OnEvent(Asteroid::Event& event) override
	{
		AS_TRACE("{0}", event);
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