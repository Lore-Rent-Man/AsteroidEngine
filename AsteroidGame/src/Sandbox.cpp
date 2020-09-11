#include "Asteroid.h"

class Sandbox : public Asteroid::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Asteroid::Application* Asteroid::CreateApplication()
{
	return new Sandbox();
}