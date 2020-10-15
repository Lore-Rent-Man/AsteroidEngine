#pragma once

#include "Asteroid/Core.h"
#include "Layer.h"

#include <vector>
namespace Asteroid {

	//Class to hold layers to dispatch events to
	//Not using std::stack because insertion may occur in the middle of the LayerStack
	class ASTEROID_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}

