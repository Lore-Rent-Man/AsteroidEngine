#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern Asteroid::Application* Asteroid::CreateApplication();

int main(int argc, char** argv)
{
	Asteroid::Log::Init();
	AS_CORE_ERROR("Initialized Log!");
	AS_WARN("Hello Printing!");

	auto app = Asteroid::CreateApplication();
	app->Run();
	delete app;
}

#endif