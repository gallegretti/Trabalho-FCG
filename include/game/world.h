#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <GLFW/glfw3.h>
#include "game/cow.h"
#include "game/player.h"
#include "game/missle.h"

class World
{
public:
    World();


    void update(move_state &actions);

    Player player;


    std::vector<Cow> cows;
    std::vector<Missle> missiles;

private:
    void updateMissiles();

    double last_fire_time = 0.0;

};
