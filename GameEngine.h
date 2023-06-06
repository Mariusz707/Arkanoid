#pragma once

#include <string>
#include <cstdlib>


#include "GraphicEngine.h"
#include "Camera.h"
#include "Inputs.h"
#include "Model.h"
#include "Game.h"

class GameEngine
{
	public:
		GameEngine() = default;
		~GameEngine() = default;

		void run();

		//void processInputs(GLFWwindow* window);

	private:

		GraphicEngine	m_graphicEngine;
		Inputs			m_inputs;
		Camera			m_camera;
		ObjectsHandler	m_objectsHandler;
		Game			m_game;



		float m_delta = 0;		
};