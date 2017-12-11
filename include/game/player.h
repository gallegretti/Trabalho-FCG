#pragma once

#include <glm/glm.hpp>

struct move_state
{
    bool up = false;
    bool down = false;
    bool foward = false;
};

class Player
{
public:
    Player();

    void update(move_state actions);


    void moveUp();
    void moveDown();

    // Posicao do jogador
    glm::vec4 position;
    glm::vec4 foward;
    glm::vec4 up;
};
