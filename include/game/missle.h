#pragma once
#include <glm/glm.hpp>
#include "matrices.h"

class Missle
{
public:

    Missle(glm::vec4 position, glm::vec4 foward);

    glm::vec4 position;
    glm::vec4 foward;
    glm::mat4 rotation_matrix;
};
