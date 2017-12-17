#pragma once
#include <glm/glm.hpp>
#include "matrices.h"
struct move_state
{
    // Movimentação
    bool up = false;
    bool down = false;
    bool foward = false;
    bool backward = false;
    bool left = false;
    bool right = false;
    // Atirar missel
    bool fire = false;
    // Rotacionar para os lados
    float dx = 0.0f;
    // Trava a camera na vaca
    bool toggle_lock_cow = false;
};

class Player
{
public:
    Player();

    void update(move_state &actions, double delta);
    void moveUp(double delta);
    void moveDown(double delta);
    void moveFoward(double delta);
    void moveBackward(double delta);
    void moveLeft(double delta);
    void moveRight(double delta);

    void yaw(float dx);

    glm::vec4 position;
    glm::vec4 foward;
    glm::vec4 up;
    glm::vec4 moving;
    glm::vec4 camera;
};
