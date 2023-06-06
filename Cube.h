#pragma once
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class Cube
{
	public:

		Cube() = default;
		Cube(unsigned int* VAO, glm::vec3 pos);
		~Cube() = default;

		void setPosition(glm::vec3 pos);
		void setColor(glm::vec3 color);
		glm::vec3 getPosition();
		glm::mat4 getModel();
		glm::vec3 getColor();


	private:

		glm::vec3	m_position;
		glm::mat4	m_model;
		glm::vec3	m_color = glm::vec3(0.f, 0.f, 0.f);

		unsigned int m_VBO = 0;
};


