#include "Cube.h"

Cube::Cube(unsigned int* VAO, glm::vec3 pos)
{
    m_position = glm::vec3(0);
    m_model = glm::mat4(1.0f);

    // size of voxel
    float vertices[] = {
        // back face
        -0.1f, -0.1f, -0.1f, 0.0f,  0.0f, 	-1.0f,
        0.1f, 0.1f, -0.1f, 0.0f,  0.0f, 	-1.0f,
        0.1f, -0.1f, -0.1f, 0.0f,  0.0f, 	-1.0f,
        0.1f, 0.1f, -0.1f, 0.0f,  0.0f, 	-1.0f,
        -0.1f, -0.1f, -0.1f, 0.0f,  0.0f, 	-1.0f,
        -0.1f, 0.1f, -0.1f, 0.0f,  0.0f, 	-1.0f,
        // front face
        -0.1f, -0.1f, 0.1f,   0.0f,  0.0f, 	 1.0f,
        0.1f, -0.1f, 0.1f,   0.0f,  0.0f, 	 1.0f,
        0.1f, 0.1f, 0.1f,   0.0f,  0.0f, 	 1.0f,
        0.1f, 0.1f, 0.1f,   0.0f,  0.0f, 	 1.0f,
        -0.1f, 0.1f, 0.1f,   0.0f,  0.0f, 	 1.0f,
        -0.1f, -0.1f, 0.1f,   0.0f,  0.0f, 	 1.0f,
        // left face
        -0.1f, 0.1f, 0.1f,  -1.0f,  0.0f, 	 0.0f,
        -0.1f, 0.1f, -0.1f,  -1.0f,  0.0f, 	 0.0f,
        -0.1f, -0.1f, -0.1f,  -1.0f,  0.0f,  0.0f,
        -0.1f, -0.1f, -0.1f,  -1.0f,  0.0f,  0.0f,
        -0.1f, -0.1f, 0.1f,  -1.0f,  0.0f, 	 0.0f,
        -0.1f, 0.1f, 0.1f,  -1.0f,  0.0f, 	 0.0f,
        // right face
        0.1f, 0.1f, 0.1f,   1.0f,  0.0f, 	 0.0f,
        0.1f, -0.1f, -0.1f,   1.0f,  0.0f, 	 0.0f,
        0.1f, 0.1f, -0.1f,   1.0f,  0.0f, 	 0.0f,
        0.1f, -0.1f, -0.1f,   1.0f,  0.0f, 	 0.0f,
        0.1f, 0.1f, 0.1f,   1.0f,  0.0f, 	 0.0f,
        0.1f, -0.1f, 0.1f,   1.0f,  0.0f, 	 0.0f,
        // bottom face
        -0.1f, -0.1f, -0.1f, 0.0f, -1.0f, 	 0.0f,
        0.1f, -0.1f, -0.1f, 0.0f, -1.0f, 	 0.0f,
        0.1f, -0.1f, 0.1f, 0.0f, -1.0f, 	 0.0f,
        0.1f, -0.1f, 0.1f, 0.0f, -1.0f, 	 0.0f,
        -0.1f, -0.1f, 0.1f, 0.0f, -1.0f, 	 0.0f,
        -0.1f, -0.1f, -0.1f, 0.0f, -1.0f, 	 0.0f,
        // top face
        -0.1f, 0.1f, -0.1f,   0.0f,  1.0f, 	 0.0f,
        0.1f, 0.1f, 0.1f,   0.0f,  1.0f, 	 0.0f,
        0.1f, 0.1f, -0.1f,   0.0f,  1.0f, 	 0.0f,
        0.1f, 0.1f, 0.1f,   0.0f,  1.0f, 	 0.0f,
        -0.1f, 0.1f, -0.1f,   0.0f,  1.0f, 	 0.0f,
        -0.1f, 0.1f, 0.1f,  0.0f,  1.0f, 	 0.0f
    };

    glGenVertexArrays(1, VAO);
    glGenBuffers(1, &m_VBO);

    glBindVertexArray(*VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    setPosition(pos);
}

glm::vec3 Cube::getPosition()
{
    return m_position;
}

void Cube::setPosition(glm::vec3 pos)
{
    glm::vec3 moveDir = pos - m_position;
    m_position = pos;
    m_model = glm::mat4(1.0f);

    m_model = glm::translate(m_model, m_position);
}


glm::mat4 Cube::getModel()
{
    return m_model;
}

glm::vec3 Cube::getColor()
{
    return m_color;
}

void Cube::setColor(glm::vec3 color)
{
    m_color = color;
}