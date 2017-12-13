#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <GLFW/glfw3.h>
#include <random>
#include "game/cow.h"
#include "game/player.h"
#include "game/missle.h"
#include <algorithm>

class World
{
public:
    World();

    // Atualiza o estado do jogo
    void update(move_state &actions);

    // Jogador
    Player player;

    // Entidades no jogo
    std::vector<Cow> cows;
    std::vector<Missle> missiles;

    // Retorna a vaca mais proxima do jogador
    Cow closestCow();

    // Camera
    glm::vec4 getCameraPosition();
    glm::vec4 getCameraLookAt();
    glm::vec4 getCameraUp();

private:
    void updateMissiles();

    void updateCows();

    double last_fire_time = 0.0;

    const int COWS = 100;

    bool looking_at_cow;

};
