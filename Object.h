#pragma once

#include "Model.h"

class Object
{
	public:

        Object() = default;
        Object(Model* textModel);
		~Object() = default;

        void setPosition(glm::vec3 pos);
        void setPos(glm::vec3 pos);
        void setModel(glm::mat4 model);
        void setShines(float shininess);
        glm::mat4 getModel();
        glm::vec3 getPosition();
        float getShininess();
        void hide();
        void unHide();
        bool isHidden();
        void move(glm::vec3 dir);

        Model* getTextModel();

    private:

        glm::vec3	m_position;
        glm::mat4	m_model;
        float       m_shininess;
        bool        m_hidden = false;
        Model*      m_textModel;
};

