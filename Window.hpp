#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <string>

class Window
{
    public:
        Window(int w, int h, std::string name);
        ~Window();

        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        bool shouldClose();
        int getInput();
        GLFWwindow* getWindow();

    private:
        bool initWindow();
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
     

        GLFWwindow* window;

        int width,height;
        std::string windowName;

        bool isRunning;
};