#pragma once
#include <glm/glm.hpp>
#include <random>

class Cow
{
public:

    Cow(glm::vec4 position);

    void update();

    glm::vec4 position;
    glm::vec4 foward;
};
