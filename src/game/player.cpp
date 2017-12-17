#include "game/player.h"

Player::Player()
{
    position = glm::vec4(-90.0f, 5.0f, 1.0f, 1.0f);
    foward = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
    camera = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
    moving = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

void Player::update(move_state &actions, double delta)
{
    // Reseta vetor up
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);

    // Faz acoes
    if (actions.up)
    {
        moveUp(delta);
    }
    if (actions.down)
    {
        moveDown(delta);
    }
    if (actions.foward)
    {
        moveFoward(delta);
    }
    if (actions.backward)
    {
        moveBackward(delta);
    }
    if (actions.left)
    {
        moveLeft(delta);
    }
    if (actions.right)
    {
        moveRight(delta);
    }
    yaw(actions.dx);

    // Clamp position to map
    if (position.x < -100.0f)
    {
        position.x = -100.0f;
    }
    if (position.x > 100.0f)
    {
        position.x = 100.0f;
    }
    if (position.z < -100.0f)
    {
        position.z = -100.0f;
    }
    if (position.z > 100.0f)
    {
        position.z = 100.0f;
    }

    // Atualiza posicao
    position += moving;

    // Faz uma desaceleração mais suave
    moving -= moving * 0.002f;

    // Efeito de perda de altitude
    position.y -= 0.0002f;

    // Zera a rotacao
    actions.dx = 0.0f;

    // Camera vai ser o vetor foward um pouco para baixo
    camera = foward * Matrix_Rotate(0.3f, crossproduct(foward, up));
}


void Player::moveUp(double delta)
{
    position += (up * ((float)delta * 2.0f));
}

void Player::moveDown(double delta)
{
    position += (-up * ((float)delta * 4.0f));
}

void Player::moveFoward(double delta)
{
    moving += (foward * ((float)delta * 0.02f));
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f) * Matrix_Rotate(0.5f, crossproduct(foward, up));
}

void Player::moveBackward(double delta)
{
    moving += (-foward * ((float)delta * 0.015f));
}

void Player::moveLeft(double delta)
{
    moving += -crossproduct(foward, up) * (float)delta * 0.015f;
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f) * Matrix_Rotate(0.05f, foward);
}

void Player::moveRight(double delta)
{
    moving += crossproduct(foward, up) * (float)delta * 0.015f;
    up = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f) * Matrix_Rotate(-0.05f, foward);
}

void Player::yaw(float dx)
{
    foward = foward * Matrix_Rotate_Y(dx * 0.005f);
}


