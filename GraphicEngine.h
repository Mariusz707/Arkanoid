#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <string>
#include <iostream>

#include "ObjectsHandler.h"
#include "Camera.h"
#include "Shader.h"
#include "Model.h"


class GraphicEngine
{
	public:
		GraphicEngine() = default;
		~GraphicEngine();

		void createWindow();
		void display(ObjectsHandler& objectsHandler, Camera& camera);

		void toggleSun();
		void toggleLights();
		void toggleLightsPos();
		void toggleWire();
		
		int isOpen();
		GLFWwindow* getWindow();

	private:
		GLFWwindow*			m_window = nullptr;
		Shader				m_shader;
		Shader				m_backShader;

		bool				m_sun = false;
		bool				m_lights = true;
		bool				m_lightsPos = true;
		bool				m_wire = true;

};