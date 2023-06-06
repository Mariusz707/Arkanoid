#include "Game.h"

void Game::init(ObjectsHandler& objectsHandler)
{
	LoadLevel(objectsHandler);
	
	objectsHandler.createSun();

	for (int i = 0; i < 3; i++)
	{
		objectsHandler.addLight(objectsHandler.getLightVAO(), glm::vec3(-7, 12 - (i * 7), 11), glm::vec3(0.9f, 0.9f, 0.9f));
		objectsHandler.addLight(objectsHandler.getLightVAO(), glm::vec3(7, 12 - (i * 7), 11), glm::vec3(0.9f, 0.9f, 0.9f));
	}
}

void Game::LoadLevel(ObjectsHandler& objectsHandler)
{
	glm::mat4 model = glm::mat4(1);

	for (int j = 0; j < 10; j++)
	{
		for (int i = -6; i < 7; i++)
		{
			objectsHandler.addObject(&objectsHandler.getAllModels()[j % 5], glm::vec3(i, 11 - (j * 0.5f), 12.5));
			m_bricks.push_back(Brick(glm::vec2(i, 11 - (j * 0.5f)), objectsHandler.getAllObjects().size() - 1));
		}
	}
	m_bricksCopy = m_bricks;

	

	objectsHandler.addObject(&objectsHandler.getAllModels()[5], glm::vec3(0, 0, 12.5));
	m_ball = &objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1];
	m_ball->setModel(glm::scale(m_ball->getModel(), glm::vec3(5, 5, 5)));

	objectsHandler.addObject(&objectsHandler.getAllModels()[6]);
	m_wall = &objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1];

	model = glm::translate(model, glm::vec3(23, 0, -11));
	model = glm::scale(model, glm::vec3(6, 3, 6));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(0, 0, 1));

	m_wall->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[7]);
	m_fences.push_back(&objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1]);
	model = glm::mat4(1);
	model = glm::translate(model, glm::vec3(-7.5, 12, 10.8));
	model = glm::scale(model, glm::vec3(1.5, 1.5, 1.5));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(1, 0, 0));
	model = glm::rotate(model, float(glm::radians(-21.5f)), glm::vec3(0, 1, 0));
	m_fences[0]->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[7]);
	m_fences.push_back(&objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1]);
	model = glm::mat4(1);
	model = glm::translate(model, glm::vec3(-7.5, 5.7, 10.8));
	model = glm::scale(model, glm::vec3(1.5, 1.5, 1.5));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(1, 0, 0));
	model = glm::rotate(model, float(glm::radians(-21.5f)), glm::vec3(0, 1, 0));

	m_fences[1]->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[7]);
	m_fences.push_back(&objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1]);
	model = glm::mat4(1);
	model = glm::translate(model, glm::vec3(-7.5, -0.6, 10.8));
	model = glm::scale(model, glm::vec3(1.5, 1.5, 1.5));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(1, 0, 0));
	model = glm::rotate(model, float(glm::radians(-21.5f)), glm::vec3(0, 1, 0));

	m_fences[2]->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[7]);
	m_fences.push_back(&objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1]);
	model = glm::mat4(1);
	model = glm::translate(model, glm::vec3(7.2, 12, 10.8));
	model = glm::scale(model, glm::vec3(1.5, 1.5, 1.5));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(1, 0, 0));
	model = glm::rotate(model, float(glm::radians(-21.5f)), glm::vec3(0, 1, 0));
	m_fences[3]->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[7]);
	m_fences.push_back(&objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1]);
	model = glm::mat4(1);
	model = glm::translate(model, glm::vec3(7.2, 5.7, 10.8));
	model = glm::scale(model, glm::vec3(1.5, 1.5, 1.5));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(1, 0, 0));
	model = glm::rotate(model, float(glm::radians(-21.5f)), glm::vec3(0, 1, 0));
	m_fences[4]->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[7]);
	m_fences.push_back(&objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1]);
	model = glm::mat4(1);
	model = glm::translate(model, glm::vec3(7.2, -0.6, 10.8));
	model = glm::scale(model, glm::vec3(1.5, 1.5, 1.5));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(1, 0, 0));
	model = glm::rotate(model, float(glm::radians(-21.5f)), glm::vec3(0, 1, 0));

	m_fences[5]->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[7]);
	m_fences.push_back(&objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1]);
	model = glm::mat4(1);
	model = glm::translate(model, glm::vec3(0, 12.1, 10.8));
	model = glm::scale(model, glm::vec3(1.8, 1.5, 1.5));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(0, 0, 1));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(1, 0, 0));
	model = glm::rotate(model, float(glm::radians(-21.5f)), glm::vec3(0, 1, 0));

	m_fences[6]->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[7]);
	m_fences.push_back(&objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1]);
	model = glm::mat4(1);
	model = glm::translate(model, glm::vec3(-7.5, 12.1, 10.8));
	model = glm::scale(model, glm::vec3(1.8, 1.5, 1.5));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(0, 0, 1));
	model = glm::rotate(model, float(glm::radians(90.f)), glm::vec3(1, 0, 0));
	model = glm::rotate(model, float(glm::radians(-21.5f)), glm::vec3(0, 1, 0));

	m_fences[7]->setModel(model);

	objectsHandler.addObject(&objectsHandler.getAllModels()[8]);
	m_paddle = &objectsHandler.getAllObjects()[objectsHandler.getAllObjects().size() - 1];
	m_paddle->setPos(glm::vec3(0, -6, 12.5));

}

void Game::update(GLFWwindow* window, ObjectsHandler& objectsHandler, float delta)
{
	glm::vec3 pos = m_paddle->getPosition();

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		m_paddle->setPos(pos + glm::vec3(1 * delta * m_ballSpeed, 0, 0));

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		m_paddle->setPos(pos + glm::vec3(-1 * delta * m_ballSpeed, 0, 0));

	if (pos.x > 5.6)
		m_paddle->setPos(glm::vec3(5.6, -6, 12.5));
	if (pos.x < -5.6)
		m_paddle->setPos(glm::vec3(-5.6, -6, 12.5));

	if (m_gameStarted == false)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			m_gameStarted = true;
		}

		m_ballDir.x = (m_paddle->getPosition().x / 5.6);

		m_ball->setPosition(pos + glm::vec3(0, 0.58, 0));
		m_ball->setModel(glm::scale(m_ball->getModel(), glm::vec3(5, 5, 5)));
	}
	else
	{
		glm::vec3 ballPos = m_ball->getPosition();

		//if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		//	m_ballDir.y = 1;
		//if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		//	m_ballDir.x = 1;

		//if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		//	m_ballDir.y = -1;

		//if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		//	m_ballDir.x = -1;

		if (ballPos.x > 7)
			m_ballDir.x *= -1;
		if (ballPos.x < -7)
			m_ballDir.x *= -1;

		if (ballPos.y > 12)
			m_ballDir.y *= -1;
		if (ballPos.y < -7)
			restartLevel(objectsHandler);


		m_ball->setPosition(ballPos + (m_ballDir * delta * m_ballSpeed));
		m_ball->setModel(glm::scale(m_ball->getModel(), glm::vec3(5, 5, 5)));

		//m_ballDir = glm::vec3(0, 0, 0);

		for (int i = 0; i < m_bricks.size(); i++)
		{
			glm::vec2 center(m_ball->getPosition() + m_ballRadius);
			glm::vec2 aabb_half_extents(m_bricks[i].getSize().x / 2.0f, m_bricks[i].getSize().y / 2.0f);
			glm::vec2 aabb_center
			(
				m_bricks[i].getPos().x + aabb_half_extents.x - 0.29,
				m_bricks[i].getPos().y + aabb_half_extents.y
			);

			// get difference vector between both centers
			glm::vec2 difference = center - aabb_center;
			glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);

			// add clamped value to AABB_center and we get the value of box closest to circle
			glm::vec2 closest = aabb_center + clamped;
			// retrieve vector between center circle and closest point AABB and check if length <= radius
			difference = closest - center;

			bool collision = glm::length(difference) < m_ballRadius;

			if (collision)
			{
				objectsHandler.getAllObjects()[m_bricks[i].getId()].hide();
				std::cout << "Col ID: " << m_bricks[i].getId() << std::endl;
				m_bricks.erase(m_bricks.begin() + i);

				Direction dir = VectorDirection(difference);

				if (dir == LEFT || dir == RIGHT) // horizontal collision
					m_ballDir.x *= -1; // reverse horizontal velocity
				else // vertical collision
				{
					m_ballDir.y *= -1; // reverse vertical velocity
				}
			}
		}

		glm::vec2 center(m_ball->getPosition() + m_ballRadius);
		glm::vec2 aabb_half_extents(m_paddleSize.x / 2.0f, m_paddleSize.y / 2.0f);
		glm::vec2 aabb_center
		(
			m_paddle->getPosition().x + aabb_half_extents.x - 1.33,
			m_paddle->getPosition().y + aabb_half_extents.y
		);

		// get difference vector between both centers
		glm::vec2 difference = center - aabb_center;
		glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);

		// add clamped value to AABB_center and we get the value of box closest to circle
		glm::vec2 closest = aabb_center + clamped;
		// retrieve vector between center circle and closest point AABB and check if length <= radius
		difference = closest - center;

		bool collision = glm::length(difference) < m_ballRadius;

		if (collision)
		{
			m_ballDir.y *= -1;
			std::cout << m_ball->getPosition().x - m_paddle->getPosition().x << std::endl;
			float dst = m_ball->getPosition().x - m_paddle->getPosition().x;

			m_ballDir.x = (dst / 1.9);
	
			m_ball->setPosition(m_ball->getPosition() + glm::vec3(0, 0.02, 0));
			m_ball->setModel(glm::scale(m_ball->getModel(), glm::vec3(5, 5, 5)));
		}

		if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
			restartLevel(objectsHandler);
	}
}

float Game::clamp(float value, float min, float max) {
	return std::max(min, std::min(max, value));
}

Direction Game::VectorDirection(glm::vec2 target)
{
	glm::vec2 compass[] = {
		glm::vec2(0.0f, 1.0f),	// up
		glm::vec2(1.0f, 0.0f),	// right
		glm::vec2(0.0f, -1.0f),	// down
		glm::vec2(-1.0f, 0.0f)	// left
	};
	float max = 0.0f;
	unsigned int best_match = -1;
	for (unsigned int i = 0; i < 4; i++)
	{
		float dot_product = glm::dot(glm::normalize(target), compass[i]);
		if (dot_product > max)
		{
			max = dot_product;
			best_match = i;
		}
	}
	return (Direction)best_match;
}

void Game::restartLevel(ObjectsHandler& objectsHandler)
{
	m_gameStarted = false;
	m_paddle->setPos(glm::vec3(0, -6, 12.5));

	m_ball->setPosition(m_paddle->getPosition() + glm::vec3(0, 0.58, 0));
	m_ball->setModel(glm::scale(m_ball->getModel(), glm::vec3(5, 5, 5)));
	m_bricks = m_bricksCopy;
	objectsHandler.allVisible();

	m_ballDir = glm::vec3(1, 0.8, 0);
}
