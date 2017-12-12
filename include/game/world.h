#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "game/cow.h"
#include "game/player.h"

class World
{
public:
    World();

    std::vector<Cow> cows;

    void update(move_state &actions);

    Player player;

};
