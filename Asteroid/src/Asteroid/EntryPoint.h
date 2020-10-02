#pragma once

#ifdef AS_PLATFORM_WINDOWS

//Entry point into application
//User creates client subclass of Application, and defines CreateApplication() 
//to return client personalized version of game engine
//argc and argv for possible terminal cmds

extern Asteroid::Application* Asteroid::CreateApplication();

int main(int argc, char** argv)
{
	Asteroid::Log::Init();

	auto app = Asteroid::CreateApplication();
	app->Run();
	delete app;
}

#endif