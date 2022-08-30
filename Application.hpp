#pragma once 

#include<filesystem>
namespace fs = std::filesystem;

#include <iostream>
#include <glad/glad.h>

#include "Window.hpp"
#include "Camera.hpp"
#include "Terrain.h"
#include "Model.hpp"

class Application
{
    public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;
    Application();
    ~Application();

    Application(const Application &) = delete;
    Application &operator=(const Application &) = delete;

    void run();

    private:
        Window window{WIDTH, HEIGHT, "Equinox"};
        Camera camera{WIDTH,HEIGHT,glm::vec3(0.0f, 0.0f, 2.0f)};

        GLFWwindow* ptrWindow;
}; 