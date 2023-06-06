#include "GraphicEngine.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GraphicEngine::~GraphicEngine()
{
    glfwTerminate();
}

void GraphicEngine::createWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(1200, 800, "Arkanoid", NULL, NULL);

    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    stbi_set_flip_vertically_on_load(true);
    glEnable(GL_DEPTH_TEST);


    m_shader.loadShader("Perspective.vs", "Colors.fs");
    m_backShader.loadShader("model_vertex.vs", "model_color.fs");

    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glFrontFace(GL_CW);
}

void GraphicEngine::display(ObjectsHandler& objectsHandler, Camera& camera)
{
    if (glfwGetKey(m_window, GLFW_KEY_1) == GLFW_PRESS)
        toggleSun();
    if (glfwGetKey(m_window, GLFW_KEY_2) == GLFW_PRESS)
        toggleLights();
    if (glfwGetKey(m_window, GLFW_KEY_3) == GLFW_PRESS)
        toggleWire();
    if (glfwGetKey(m_window, GLFW_KEY_4) == GLFW_PRESS)
        toggleLightsPos();


    if(m_wire)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(m_shader.getShaderProgram());

    unsigned int modelLoc = glGetUniformLocation(m_shader.getShaderProgram(), "model");
    unsigned int viewLoc = glGetUniformLocation(m_shader.getShaderProgram(), "view");
    unsigned int projectionLoc = glGetUniformLocation(m_shader.getShaderProgram(), "projection");
    unsigned int colorLoc = glGetUniformLocation(m_shader.getShaderProgram(), "ourColor");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &camera.getView()[0][0]);
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &camera.getProjection()[0][0]);

    if (objectsHandler.getAllCubes().size() != 0)
    {
        for (int i = 0; i < objectsHandler.getAllCubes().size(); i++)
        {
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &(objectsHandler.getAllCubes()[i].getModel()[0][0]));
            glUniform3fv(colorLoc, 1, &(objectsHandler.getAllCubes()[i].getColor()[0]));

            glBindVertexArray(*objectsHandler.getCubeVAO());
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
    }

    if (m_lightsPos)
    {
        if (objectsHandler.getAllLights().size() != 0)
        {
            for (int i = 0; i < objectsHandler.getAllLights().size(); i++)
            {
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &(objectsHandler.getAllLights()[i].getModel()[0][0]));
                glUniform3fv(colorLoc, 1, &(objectsHandler.getAllLights()[i].getColor()[0]));

                glBindVertexArray(*objectsHandler.getLightVAO());
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
        }
    }
    glUseProgram(m_backShader.getShaderProgram());


    //LIGHTS !!! _____________________________________________________________________________________________________________________________________________

    modelLoc = glGetUniformLocation(m_backShader.getShaderProgram(), "model");
    viewLoc = glGetUniformLocation(m_backShader.getShaderProgram(), "view");
    projectionLoc = glGetUniformLocation(m_backShader.getShaderProgram(), "projection");

    unsigned int viewPos = glGetUniformLocation(m_backShader.getShaderProgram(), "viewPos");

    unsigned int sunDirection = glGetUniformLocation(m_backShader.getShaderProgram(), "dirLight.direction");
    unsigned int sunAmbient = glGetUniformLocation(m_backShader.getShaderProgram(), "dirLight.ambient");
    unsigned int sunDiffuse = glGetUniformLocation(m_backShader.getShaderProgram(), "dirLight.diffuse");
    unsigned int sunSpecular = glGetUniformLocation(m_backShader.getShaderProgram(), "dirLight.specular");

    unsigned int lightsSize = glGetUniformLocation(m_backShader.getShaderProgram(), "lightsSize");
    if (m_lights)
        glUniform1i(lightsSize, objectsHandler.getAllLights().size());
    else
        glUniform1i(lightsSize, 0);

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &camera.getView()[0][0]);
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &camera.getProjection()[0][0]);
    

    for (int i = 0; i < objectsHandler.getAllLights().size(); i++)
    {
        unsigned int lightPosistion = glGetUniformLocation(m_backShader.getShaderProgram(), std::string("pointLights[" + std::to_string(i) + "].position").c_str());
        unsigned int lightAmbient = glGetUniformLocation(m_backShader.getShaderProgram(), std::string("pointLights[" + std::to_string(i) + "].ambient").c_str());
        unsigned int lightDiffuse = glGetUniformLocation(m_backShader.getShaderProgram(), std::string("pointLights[" + std::to_string(i) + "].diffuse").c_str());
        unsigned int lightSpecular = glGetUniformLocation(m_backShader.getShaderProgram(), std::string("pointLights[" + std::to_string(i) + "].specular").c_str());
        unsigned int lightConstant = glGetUniformLocation(m_backShader.getShaderProgram(), std::string("pointLights[" + std::to_string(i) + "].constant").c_str());
        unsigned int lightLinear = glGetUniformLocation(m_backShader.getShaderProgram(), std::string("pointLights[" + std::to_string(i) + "].linear").c_str());
        unsigned int lightQuadratic = glGetUniformLocation(m_backShader.getShaderProgram(), std::string("pointLights[" + std::to_string(i) + "].quadratic").c_str());

        glUniform3fv(lightPosistion, 1, &(objectsHandler.getAllLights()[i].getPosition()[0]));
        glUniform3fv(lightAmbient, 1, &(objectsHandler.getAllLights()[i].getAmbient()[0]));
        glUniform3fv(lightDiffuse, 1, &(objectsHandler.getAllLights()[i].getDiffuse()[0]));
        glUniform3fv(lightSpecular, 1, &(objectsHandler.getAllLights()[i].getSpecular()[0]));
        glUniform1f(lightConstant, objectsHandler.getAllLights()[i].getConstant());
        glUniform1f(lightLinear, objectsHandler.getAllLights()[i].getLinear());
        glUniform1f(lightQuadratic, objectsHandler.getAllLights()[i].getQuadratic());
    }


    glUniform3fv(viewPos, 1, &camera.getPosition()[0]);

    if (m_sun)
    {
        glUniform3fv(sunDirection, 1, &objectsHandler.getSun()->getDirection()[0]);
        glUniform3fv(sunAmbient, 1, &objectsHandler.getSun()->getAmbient()[0]);
        glUniform3fv(sunDiffuse, 1, &objectsHandler.getSun()->getDiffuse()[0]);
        glUniform3fv(sunSpecular, 1, &objectsHandler.getSun()->getSpecular()[0]);
    }

    // render the loaded model
    unsigned int locShininess = glGetUniformLocation(m_backShader.getShaderProgram(), "material.shininess");

    for (int i = 0; i < objectsHandler.getAllObjects().size(); i++)
    {
        if(objectsHandler.getAllObjects()[i].isHidden() == false)
        {
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &(objectsHandler.getAllObjects()[i].getModel()[0][0]));
            glUniform1f(locShininess, objectsHandler.getAllObjects()[i].getShininess());
            objectsHandler.getAllObjects()[i].getTextModel()->Draw(m_backShader);
        }
    }

    
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void GraphicEngine::toggleSun()
{
    if (m_sun)
        m_sun = false;
    else
        m_sun = true;
}

void GraphicEngine::toggleLights()
{
    if (m_lights)
        m_lights = false;
    else
        m_lights = true;
}

void GraphicEngine::toggleLightsPos()
{
    if (m_lightsPos)
        m_lightsPos = false;
    else
        m_lightsPos = true;
}


void GraphicEngine::toggleWire()
{
    if (m_wire)
        m_wire = false;
    else
        m_wire = true;
}

int GraphicEngine::isOpen()
{
    return glfwWindowShouldClose(m_window);
}

GLFWwindow* GraphicEngine::getWindow()
{
    return m_window;
}