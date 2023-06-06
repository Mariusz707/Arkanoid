#include "Object.h"

Object::Object(Model* textModel)
{
    m_textModel = textModel;
    m_shininess = 2;
}

void Object::setPosition(glm::vec3 pos)
{
    m_model = glm::mat4(1);
    m_position = pos;

    m_model = glm::translate(m_model, m_position);
    m_model = glm::scale(m_model, glm::vec3(0.045, 0.045, 0.045));
    m_model = glm::rotate(m_model, float(glm::radians(-90.f)), glm::vec3(0, 1, 0));
    m_model = glm::rotate(m_model, float(glm::radians(90.f)), glm::vec3(0, 0, 1));
}

void Object::setPos(glm::vec3 pos)
{
    m_model = glm::mat4(1);
    m_position = pos;

    m_model = glm::mat4(1);
    m_model = glm::translate(m_model, pos);
    m_model = glm::scale(m_model, glm::vec3(0.145, 0.07, 0.045));
    m_model = glm::rotate(m_model, float(glm::radians(-90.f)), glm::vec3(0, 1, 0));
    m_model = glm::rotate(m_model, float(glm::radians(90.f)), glm::vec3(0, 0, 1));
}

void Object::setModel(glm::mat4 model)
{
    m_model = model;
}

void Object::setShines(float shininess)
{
    m_shininess = shininess;
}

glm::mat4 Object::getModel()
{
    return m_model;
}

glm::vec3 Object::getPosition()
{
    return m_position;
}

float Object::getShininess()
{
    return m_shininess;
}

void Object::hide()
{
    m_hidden = true;
}

void Object::unHide()
{
    m_hidden = false;
}

bool Object::isHidden()
{
    return m_hidden;
}

void Object::move(glm::vec3 dir)
{
    m_model = glm::translate(m_model, dir);
}

Model* Object::getTextModel()
{
    return m_textModel;
}
