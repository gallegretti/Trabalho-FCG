#pragma once
#include <glm/glm.hpp>

class Missle
{
public:

    Missle(glm::vec4 position, glm::vec4 foward);

    glm::vec4 position;
    glm::vec4 foward;
};
