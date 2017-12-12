#include "game/world.h"

World::World()
{
    // TODO: Gerar N vacas aleatorias
    cows = { Cow(glm::vec4(5.0f, -0.5f, 0.0f, 1.0f)), Cow(glm::vec4(-5.0f, -0.5f, 0.0f, 1.0f)) };
}

