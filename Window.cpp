#include "Window.hpp"


Window::Window(int w, int h, std::string name)
    : width{w}, height{h}, windowName{name}, isRunning{true}
    {
  initWindow();
    }

Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::initWindow()
    {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

        // glfw window creation
    // --------------------
    window = glfwCreateWindow(width,height,windowName.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    
    return true;
    }

bool Window::shouldClose()
{
    return !isRunning;
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
     // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
int Window::getInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
        isRunning=false;
    }
    return 0;
}

 GLFWwindow* Window::getWindow()
 {
     return window;
 }




