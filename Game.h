#pragma once

#include <glm/glm.hpp>
#include <string>

#include "ObjectsHandler.h"
#include "Object.h"
#include "Brick.h"

enum Direction 
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Game
{
	public:
		Game() = default;
		~Game() = default;

		void init(ObjectsHandler& objectsHandler);
		void LoadLevel(ObjectsHandler& objectsHandler);

		float clamp(float value, float min, float max);

		void update(GLFWwindow* window, ObjectsHandler& objectsHandler, float delta);
		Direction VectorDirection(glm::vec2 target);
		void restartLevel(ObjectsHandler& objectsHandler);

	private:

		Object*							m_wall;
		std::vector<Object*>			m_fences;
		std::vector<Brick>				m_bricks;
		std::vector<Brick>				m_bricksCopy;

		Object*							m_ball;
		float							m_ballSpeed = 10;
		float							m_ballRadius = 0.2f;
		glm::vec3						m_ballDir = glm::vec3(1, 0.8, 0);

		Object*							m_paddle;
		float							m_paddleSpeed = 25;
		glm::vec2						m_paddleSize = glm::vec2(3.15, 0.58);
		bool							m_gameStarted = false;
};

