#include "game/cow.h"

Cow::Cow(glm::vec4 position)
{
    this->position = position;
    //this->foward = foward;
}

void Cow::update()
{
    // TODO: Fazer algo melhor aqui
    position.x += 0.01f;
    if (position.x > 100.0f)
    {
        position.x = -100.0f;
    }
}
