#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "game/cow.h"

class World
{
public:
    World();

    std::vector<Cow> cows;

};
