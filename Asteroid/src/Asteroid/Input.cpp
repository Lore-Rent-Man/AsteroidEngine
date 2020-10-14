#include "aspch.h"

#include "Asteroid/Input.h"

namespace Asteroid
{
	bool Input::IsKeyPressed(int keycode) { 
		return Input::s_Instance->IsKeyPressedImpl(keycode); 
	}
	
	bool Input::IsMouseButtonPressed(int button) { 
		return Input::s_Instance->IsMouseButtonPressedImpl(button); 
	}
	float Input::GetMouseX() { 
		return Input::s_Instance->GetMouseXImpl(); 
	}
	float Input::GetMouseY() { 
		return Input::s_Instance->GetMouseYImpl(); 
	}
	std::pair<float, float> Input::GetMousePos() { 
		return Input::s_Instance->GetMousePosImpl(); 
	}
}
