#include "game/player.h"

Player::Player()
{
    position = glm::vec4(1.0f, 5.0f, 1.0f, 1.0f);
    foward = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
}

void Player::update(move_state actions)
{
    if (actions.up)
    {
        moveUp();
    }
    if (actions.down)
    {
        moveDown();
    }
}


void Player::moveUp()
{
    position = position + (up * 0.01f);
}

void Player::moveDown()
{
    position = position + (-up * 0.01f);
}
