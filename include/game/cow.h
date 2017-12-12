#pragma once
#include <glm/glm.hpp>

class Cow
{
public:

    Cow(glm::vec4 position);

    glm::vec4 position;
    glm::vec4 foward;
};
