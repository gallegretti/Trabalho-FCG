#pragma once
#include <stb_image.h>
#include <tiny_obj_loader.h>

class Terrain
{
public:
    Terrain();

    void deformTerrain(tinyobj::attrib_t &terrain);

    float getHeight(float x, float z);

private:
    unsigned char *data;

    float deformation_intensity = 0.05f;

    int length;
};
