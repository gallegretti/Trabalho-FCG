#pragma once

#include <glm/glm.hpp>
#include <list>
#include <GLFW/glfw3.h>
#include <random>
#include "game/cow.h"
#include "game/player.h"
#include "game/missle.h"
#include "game/terrain.h"
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
    std::list<Cow> cows;
    std::list<Missle> missiles;

    // Retorna a vaca mais proxima do jogador
    Cow closestCow();

    // Camera
    glm::vec4 getCameraPosition();
    glm::vec4 getCameraLookAt();
    glm::vec4 getCameraUp();

    // Score
    int score = 0;

    Terrain terrain;

private:
    void updateMissiles();

    void updateCows();

    void updateCollisions();

    double last_fire_time = 0.0;

    const int COWS = 100;

    bool looking_at_cow;

};
