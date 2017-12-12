#include "game/world.h"

World::World()
{
    // TODO: Gerar N vacas aleatorias
    cows = { Cow(glm::vec4(5.0f, -0.5f, 0.0f, 1.0f)), Cow(glm::vec4(-5.0f, -0.5f, 0.0f, 1.0f)) };
}

void World::update(move_state &actions)
{
    player.update(actions);

    // Checa cooldown
    double current_time = glfwGetTime();
    if (actions.fire && (current_time - last_fire_time) > 1.0)
    {
        last_fire_time = current_time;
        missiles.push_back(Missle(player.position, player.camera));
    }
    // Desmarca a acao
    actions.fire = false;

    updateMissiles();
}

void World::updateMissiles()
{
    for (auto &missle : missiles)
    {
        // TODO: Esse foward eh sempre unitario?
        missle.position += missle.foward * 0.05f;
        // TODO: Checar por colisoes
        // TODO: Checar se saiu fora do mapa, e remover
    }
}
