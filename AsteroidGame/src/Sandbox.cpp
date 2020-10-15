#include "Asteroid.h"

#include "imgui/imgui.h"

class ExampleLayer : public Asteroid::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Text");
		ImGui::Text("Hello world!");
		ImGui::End();
	}

	void OnUpdate() override
	{
		if (Asteroid::Input::IsKeyPressed(AS_KEY_TAB))
			AS_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Asteroid::Event& event) override
	{
		if (event.GetEventType() == Asteroid::EventType::KeyPressed)
		{
			Asteroid::KeyPressedEvent& e = (Asteroid::KeyPressedEvent&) event;
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
	}

	~Sandbox()
	{

	}
};

Asteroid::Application* Asteroid::CreateApplication()
{
	return new Sandbox();
}