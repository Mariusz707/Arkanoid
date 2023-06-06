#include "Brick.h"

Brick::Brick(glm::vec2 pos,	int id)
{
	m_pos = pos;
	m_id = id;
}

glm::vec2 Brick::getPos()
{
	return m_pos;
}

glm::vec2 Brick::getSize()
{
	return m_size;
}

int Brick::getId()
{
	return m_id;
}
