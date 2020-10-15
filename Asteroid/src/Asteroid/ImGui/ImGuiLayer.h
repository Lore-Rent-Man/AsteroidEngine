#pragma once

#include "Asteroid/Layer.h"

#include "Asteroid/Events/ApplicationEvent.h"
#include "Asteroid/Events/KeyEvent.h"
#include "Asteroid/Events/MouseEvent.h"

namespace Asteroid {

	class ASTEROID_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		
		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}