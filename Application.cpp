#include "Application.hpp"



Application::Application(){
        ptrWindow = window.getWindow();

}

Application::~Application(){
}

void Application::run(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);

    Shader shaderProgram("resources/shaders/default.vert", "resources/shaders/default.frag");
    // Take care of all the light related things
    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::mat4 lightModel = glm::mat4(1.0f);
    lightModel = glm::translate(lightModel, lightPos);
    shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	std::string modelPath = "resources/models/bunny/scene.gltf";
	// Load in a model
	Model model(modelPath.c_str());

    
    
    
    while(!window.shouldClose()){
        glClearColor(0.015f,0.388,0.792, 1.0f);
        // Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs
		camera.Inputs(ptrWindow);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.UpdateMatrix(45.0f, 0.1f, 100.0f);

		// Draw a model
		model.Draw(shaderProgram, camera);

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(ptrWindow);
		// Take care of all GLFW events
		glfwPollEvents();
        window.getInput();
    }

    shaderProgram.Delete();
   
}