#pragma once 

#include "Window.hpp"

class Renderer
{
    public:
    Renderer(Window &_window);
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

    private:
        Window &window;

};