#pragma once

#include <glm/glm.hpp>

class Brick
{
	public:
		Brick() = default;
		Brick(glm::vec2 pos, int id);
		~Brick() = default;

		glm::vec2 getPos();
		glm::vec2 getSize();
		int getId();

	private:

		int				m_id;
		glm::vec2		m_pos;
		glm::vec2		m_size = glm::vec2(0.95, 0.4);
			
		//		0.9
		//	_____________
		//	|			|
		//	|			| 0.4
		//	-------------
};

