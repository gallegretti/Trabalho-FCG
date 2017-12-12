#include "game/player.h"

Player::Player()
{
    position = glm::vec4(-100.0f, 5.0f, 1.0f, 1.0f);
    foward = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
    moving = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

void Player::update(move_state &actions)
{
    // Reseta vetor up
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);

    // Faz acoes
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
    yaw(actions.dx);

    // Atualiza posicao
    position += moving;

    // Faz uma desaceleração mais suave
    moving -= moving * 0.002f;

    // Efeito de perda de altitude
    position.y -= 0.0001f;

    // Colisão com o chão
    if (position.y < 0)
    {
        position.y = 0;
    }

    // Zera a rotacao
    actions.dx = 0.0f;
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
    moving += (foward * 0.00002f);
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f) * Matrix_Rotate(0.5f, crossproduct(foward, up));
}

void Player::moveBackward()
{
    moving += (-foward * 0.000015f);
}

void Player::moveLeft()
{
    moving += -crossproduct(foward, up) * 0.000015f;
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f) * Matrix_Rotate(0.05f, foward);
}

void Player::moveRight()
{
    moving += crossproduct(foward, up) * 0.000015f;
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f) * Matrix_Rotate(-0.05f, foward);
}

void Player::yaw(float dx)
{
    foward = foward * Matrix_Rotate_Y(dx * 0.005f);
}


