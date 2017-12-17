#include "game/cow.h"

Cow::Cow(glm::vec4 position)
{
    this->position = position;
    //this->foward = foward;
}

void Cow::update(double delta)
{
    // TODO: Fazer algo melhor aqui
    position.x += 2.0f * delta;
    if (position.x > 100.0f)
    {
        position.x = -100.0f;
    }
}

glm::vec4 Cow::collisionSphereCenter()
{
    // TODO: Ajustar
    return position;
}

float Cow::collisionSphereRadius()
{
    return 0.8f;
}
