#include "game/world.h"

World::World()
{
    // Gera algumas vacas
    cows.reserve(COWS);
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(-100.0f, 100.0f);
    for (auto i = 0; i < COWS; i++)
    {
        auto random_position = glm::vec4(distribution(generator),0.0f,distribution(generator), 1.0f);
        cows.push_back(random_position);
    }
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
    updateCows();
}

void World::updateCows()
{
    for (auto &cow : cows)
    {
        cow.update();
    }
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
