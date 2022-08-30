#pragma once

#include "FileLoader.h"

#include <glad/glad.h>

#define ABOVE_WATER 1
#define UNDER_WATER -1
#define DONT_CLIP 0

class Terrain
{
    public:
    Terrain();
    ~Terrain();

    Terrain(const Terrain &) = delete;
    Terrain &operator=(const Terrain &) = delete;

    private:
    void initTerrain();

};