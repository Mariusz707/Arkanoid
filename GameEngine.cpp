#include "GameEngine.h"

void GameEngine::run()
{
	m_graphicEngine.createWindow();
	glfwSetWindowUserPointer(m_graphicEngine.getWindow(), &m_inputs);
	m_camera.createCamera(m_graphicEngine.getWindow(), &m_delta);

	m_inputs = Inputs(m_graphicEngine.getWindow());

	m_objectsHandler.loadModels();

	//m_objectsHandler.addCube(m_objectsHandler.getCubeVAO(), glm::vec3(10, 0, 0));
	//m_objectsHandler.getAllCubes()[0].setColor(glm::vec3(1, 0, 0));
	//m_objectsHandler.addCube(m_objectsHandler.getCubeVAO(), glm::vec3(0, 10, 0));
	//m_objectsHandler.getAllCubes()[1].setColor(glm::vec3(0, 1, 0));
	//m_objectsHandler.addCube(m_objectsHandler.getCubeVAO(), glm::vec3(0, 0, 10));
	//m_objectsHandler.getAllCubes()[2].setColor(glm::vec3(0, 0, 1));



	//m_objectsHandler.addCube(m_objectsHandler.getCubeVAO(), glm::vec3(-7, -12, 12));
	//m_objectsHandler.getAllCubes()[3].setColor(glm::vec3(1, 0, 1));
	//m_objectsHandler.addCube(m_objectsHandler.getCubeVAO(), glm::vec3(7, -12, 12));
	//m_objectsHandler.getAllCubes()[4].setColor(glm::vec3(1, 0, 1));

	//m_objectsHandler.addCube(m_objectsHandler.getCubeVAO(), glm::vec3(-7, 12, 12));
	//m_objectsHandler.getAllCubes()[5].setColor(glm::vec3(1, 0, 1));
	//m_objectsHandler.addCube(m_objectsHandler.getCubeVAO(), glm::vec3(7, 12, 12));
	//m_objectsHandler.getAllCubes()[6].setColor(glm::vec3(1, 0, 1));


	//m_objectsHandler.addCube(m_objectsHandler.getCubeVAO(), glm::vec3(0, 0, 0));
	//m_objectsHandler.getAllCubes()[7].setColor(glm::vec3(0, 1, 1));

	//m_objectsHandler.addBrick(m_graphicEngine.getBrickVAO(), glm::vec3(1, -1, 1));
	//m_objectsHandler.addBrick(m_graphicEngine.getBrickVAO(), glm::vec3(1, -1, -1));
	//m_objectsHandler.addBrick(m_graphicEngine.getBrickVAO(), glm::vec3(-1, -1, 1));

	//m_objectsHandler.addBrick(m_graphicEngine.getBrickVAO(), glm::vec3(1, 1, -1));
	//m_objectsHandler.addBrick(m_graphicEngine.getBrickVAO(), glm::vec3(-1, 1, 1));
	//m_objectsHandler.addBrick(m_graphicEngine.getBrickVAO(), glm::vec3(-1, 1, -1));

	//std::string path = "resources//brick//brick01a.obj";
	//m_objectsHandler.addModel(path, glm::vec3(2, -4, 1));
	//m_objectsHandler.getAllModels()[0].setShines(64);
	//m_objectsHandler.getAllModels()[0].setModel(glm::scale(m_objectsHandler.getAllModels()[0].getModel(), glm::vec3(0.05, 0.05, 0.05)));
	//m_objectsHandler.getAllModels()[0].setModel(glm::rotate(m_objectsHandler.getAllModels()[0].getModel(), float(glm::radians(-90.f)), glm::vec3(0, 1, 0)));
	//m_objectsHandler.getAllModels()[0].setModel(glm::rotate(m_objectsHandler.getAllModels()[0].getModel(), float(glm::radians(-90.f)), glm::vec3(0, 0, 1)));
	//path = "resources//brick//brick01b.obj";
	//m_objectsHandler.addModel(path, glm::vec3(2, -2, 1));
	//m_objectsHandler.getAllModels()[1].setShines(64);
	//m_objectsHandler.getAllModels()[1].setModel(glm::scale(m_objectsHandler.getAllModels()[1].getModel(), glm::vec3(0.05, 0.05, 0.05)));
	//m_objectsHandler.getAllModels()[1].setModel(glm::rotate(m_objectsHandler.getAllModels()[1].getModel(), float(glm::radians(-90.f)), glm::vec3(0, 1, 0)));
	//m_objectsHandler.getAllModels()[1].setModel(glm::rotate(m_objectsHandler.getAllModels()[1].getModel(), float(glm::radians(90.f)), glm::vec3(0, 0, 1)));
	//path = "resources//brick//brick01c.obj";
	//m_objectsHandler.addModel(path, glm::vec3(2, 0, 1));
	//m_objectsHandler.getAllModels()[2].setShines(64);
	//m_objectsHandler.getAllModels()[2].setModel(glm::scale(m_objectsHandler.getAllModels()[2].getModel(), glm::vec3(0.05, 0.05, 0.05)));
	//path = "resources//brick//brick01d.obj";
	//m_objectsHandler.addModel(path, glm::vec3(2, 2, 1));
	//m_objectsHandler.getAllModels()[3].setShines(64);
	//m_objectsHandler.getAllModels()[3].setModel(glm::scale(m_objectsHandler.getAllModels()[3].getModel(), glm::vec3(0.05, 0.05, 0.05)));
	//path = "resources//brick//brick01e.obj";
	//m_objectsHandler.addModel(path, glm::vec3(2, 4, 1));
	//m_objectsHandler.getAllModels()[4].setShines(64);
	//m_objectsHandler.getAllModels()[4].setModel(glm::scale(m_objectsHandler.getAllModels()[4].getModel(), glm::vec3(0.05, 0.05, 0.05)));
	//path = "resources//brick//brick01f.obj";
	//m_objectsHandler.addModel(path, glm::vec3(2, 6, 1));
	//m_objectsHandler.getAllModels()[5].setShines(64);
	//m_objectsHandler.getAllModels()[5].setModel(glm::scale(m_objectsHandler.getAllModels()[5].getModel(), glm::vec3(0.05, 0.05, 0.05)));
	//path = "resources//brick//brick01g.obj";
	//m_objectsHandler.addModel(path, glm::vec3(2, 8, 1));
	//m_objectsHandler.getAllModels()[6].setShines(64);
	//m_objectsHandler.getAllModels()[6].setModel(glm::scale(m_objectsHandler.getAllModels()[6].getModel(), glm::vec3(0.05, 0.05, 0.05)));

	//path = "resources//skull//12140_Skull_v3_L2.obj";
	//m_objectsHandler.addModel(path, glm::vec3(0, 2, 0));
	//m_objectsHandler.getAllModels()[3].setModel(glm::scale(m_objectsHandler.getAllModels()[1].getModel(), glm::vec3(0.5, 0.5, 0.5)));
	//m_objectsHandler.getAllModels()[3].setModel(glm::rotate(m_objectsHandler.getAllModels()[1].getModel(), float(glm::radians(-90.f)), glm::vec3(1, 0, 0)));
	//m_objectsHandler.getAllModels()[3].setShines(64);

	//path = "resources//land//mount.blend1.obj";
	//m_objectsHandler.addModel(path, glm::vec3(0, -40, 0));
	//m_objectsHandler.getAllModels()[3].setModel(glm::scale(m_objectsHandler.getAllModels()[1].getModel(), glm::vec3(2, 2, 2)));
	//m_objectsHandler.getAllModels()[3].setShines(0);

	m_game.init(m_objectsHandler);


	while (!m_graphicEngine.isOpen())
	{
		//Input 
		m_inputs.update();
		//Game
		m_game.update(m_graphicEngine.getWindow(), m_objectsHandler, m_delta);
		//resolveCollsions();
		//Camera
		m_camera.update(m_inputs.getMouseStatus());
		//World
		//GUI
		//AI
		//Audio
		//Render


		m_graphicEngine.display(m_objectsHandler, m_camera);

		//std::cout << m_inputs.getMouseStatus()->m_scrollValue << std::endl;

		m_delta = (float)glfwGetTime();
		glfwSetTime(0);
		//m_inputs.getMouseStatus()->reset();
	}

}