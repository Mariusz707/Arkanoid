#include "ObjectsHandler.h"

void ObjectsHandler::addCube(unsigned int* VAO, glm::vec3 pos)
{
    m_cubes.push_back(Cube(VAO, pos));
}

void ObjectsHandler::addLight(unsigned int* VAO, glm::vec3 pos, glm::vec3 color)
{
    m_lights.push_back(Light(VAO));

    m_lights[m_lights.size() - 1].setColor(color);
    m_lights[m_lights.size() - 1].setAmbient(glm::vec3(0.05f, 0.05f, 0.05f));
    m_lights[m_lights.size() - 1].setDiffuse(glm::vec3(0.9f, 0.9f, 0.9f));
    m_lights[m_lights.size() - 1].setSpecular(glm::vec3(1.0f, 1.0f, 1.0f));
    m_lights[m_lights.size() - 1].setConstant(1.0f);
    m_lights[m_lights.size() - 1].setLinear(0.09f);
    m_lights[m_lights.size() - 1].setQuadratic(0.032f);

    m_lights[m_lights.size() - 1].setPosition(pos);
}

void ObjectsHandler::addObject(Model* model, glm::vec3 pos)
{
    m_objects.push_back(Object(model));

    m_objects[m_objects.size() - 1].setPosition(pos);
}

void ObjectsHandler::loadModels()
{
	std::string path;

    path = "resources//brick//brick01c.obj";
    m_models.push_back(Model(path));
	path = "resources//brick//brick01d.obj";
    m_models.push_back(Model(path));
    path = "resources//brick//brick01e.obj";
    m_models.push_back(Model(path));
    path = "resources//brick//brick01f.obj";
    m_models.push_back(Model(path));
    path = "resources//brick//brick01g.obj";
    m_models.push_back(Model(path));
    path = "resources//Ball//Ball.obj";
    m_models.push_back(Model(path));
    path = "resources//concrete_wall//concrete_wall.obj";
    m_models.push_back(Model(path));
    path = "resources//fence//fence.obj";
    m_models.push_back(Model(path));
    path = "resources//brick//brick01a.obj";
    m_models.push_back(Model(path));
}


void ObjectsHandler::createSun()
{
    m_sun.setDirection(glm::vec3(-0.2f, -1.0f, 0.3f));
    m_sun.setAmbient(glm::vec3(0.05f, 0.05f, 0.05f));
    m_sun.setDiffuse(glm::vec3(0.6f, 0.6f, 0.6f));
    m_sun.setSpecular(glm::vec3(0.5f, 0.5f, 0.5f));
}

Light* ObjectsHandler::getSun()
{
    return &m_sun;
}

std::vector<Cube>& ObjectsHandler::getAllCubes()
{
    return m_cubes;
}

std::vector<Model>& ObjectsHandler::getAllModels()
{
    return m_models;
}

std::vector<Light>& ObjectsHandler::getAllLights()
{
    return m_lights;
}

std::vector<Object>& ObjectsHandler::getAllObjects()
{
    return m_objects;
}

unsigned int* ObjectsHandler::getCubeVAO()
{
    return &m_cubesVAO;
}

unsigned int* ObjectsHandler::getLightVAO()
{
    return &m_lightVAO;
}

void ObjectsHandler::allVisible()
{
    for (int i = 0; i < m_objects.size(); i++)
        m_objects[i].unHide();
}
