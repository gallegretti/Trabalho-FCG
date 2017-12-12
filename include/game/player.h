#pragma once
#include <glm/glm.hpp>
#include "matrices.h"
struct move_state
{
    bool up = false;
    bool down = false;
    bool foward = false;
    bool backward = false;
    bool left = false;
    bool right = false;
};

class Player
{
public:
    Player();

    void update(move_state actions);
    void moveUp();
    void moveDown();
    void moveFoward();
    void moveBackward();
    void moveLeft();
    void moveRight();

    glm::vec4 position;
    glm::vec4 foward;
    glm::vec4 up;
    glm::vec4 moving;
};
