#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "Cube.h"
#include "Model.h"
#include "Light.h"
#include "Object.h"

class ObjectsHandler
{
	public:
		ObjectsHandler() = default;
		~ObjectsHandler() = default;

		void createSun();

		void addCube(unsigned int* VAO, glm::vec3 pos);
		void addLight(unsigned int* VAO, glm::vec3 pos, glm::vec3 color);
		void addObject(Model* model, glm::vec3 pos = glm::vec3(0, 0 ,0));
		void loadModels();

		Light* getSun();
		std::vector<Cube>& getAllCubes();
		std::vector<Model>& getAllModels();
		std::vector<Light>& getAllLights();
		std::vector<Object>& getAllObjects();
		unsigned int* getCubeVAO();
		unsigned int* getLightVAO();

		void allVisible();

	private:

		Light					m_sun;
		std::vector<Cube>		m_cubes;
		std::vector<Model>		m_models;
		std::vector<Light>		m_lights;
		std::vector<Object>		m_objects;

		unsigned int			m_cubesVAO = 0;
		unsigned int			m_lightVAO = 3;
};