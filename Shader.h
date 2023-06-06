#pragma once

#include <fstream>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Shader
{
	public:
		Shader() = default;
		~Shader() = default;
		bool loadShader(std::string vertexName, std::string FragmentName);
		bool loadVertexShader(std::string fileName);
		bool loadFragmentShader(std::string fileName);

		unsigned int getShaderProgram();

	private:
		unsigned int m_vertexShader;
		unsigned int m_fragmentShader;

		unsigned int m_shaderProgram;
};
