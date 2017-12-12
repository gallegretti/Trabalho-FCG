#include "game/player.h"

Player::Player()
{
    position = glm::vec4(-100.0f, 5.0f, 1.0f, 1.0f);
    foward = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
    moving = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
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
    if (actions.foward)
    {
        moveFoward();
    }
    if (actions.backward)
    {
        moveBackward();
    }
    if (actions.left)
    {
        moveLeft();
    }
    if (actions.right)
    {
        moveRight();
    }

    // Limita velocidade maxima no plano x/y
    /*
    float horizontal_speed = sqrt(moving.x*moving.x + moving.y*moving.y);
    if (horizontal_speed > 1.0f)
    {
        moving.x /= horizontal_speed;
        moving.y /= horizontal_speed;
    }
    */

    position += moving;

    // Faz uma desaceleração mais suave
    moving = moving * 0.995f;

    // Efeito de perda de altitude
    position.y -= 0.0001f;

    // Colisão com o chão
    if (position.y < 0)
    {
        position.y = 0;
    }
}


void Player::moveUp()
{
    position += (up * 0.002f);
}

void Player::moveDown()
{
    position += (-up * 0.004f);
}

void Player::moveFoward()
{
    moving += (foward * 0.00005f);
}

void Player::moveBackward()
{
    moving += (-foward * 0.00005f);
}

void Player::moveLeft()
{
    moving += -crossproduct(foward, up) * 0.00005f;
}

void Player::moveRight()
{
    moving += crossproduct(foward, up) * 0.00005f;
}



