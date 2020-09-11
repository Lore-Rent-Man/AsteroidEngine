#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern Asteroid::Application* Asteroid::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Asteroid::CreateApplication();
	app->Run();
	delete app;
}

#endif