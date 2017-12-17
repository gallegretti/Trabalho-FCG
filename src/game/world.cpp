#include "game/world.h"

World::World()
{
    // Gera algumas vacas
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(-100.0f, 100.0f);
    for (auto i = 0; i < COWS; i++)
    {
        auto random_position = glm::vec4(distribution(generator),0.0f,distribution(generator), 1.0f);
        cows.push_back(random_position);
    }
    looking_at_cow = false;
}

void World::update(move_state &actions)
{
    player.update(actions);
    // Colisão com o chão
    player.position.y = std::max(player.position.y, terrain.getHeight(player.position.x, player.position.z));


    // Olhando para a vaca?
    if (actions.toggle_lock_cow)
    {
        looking_at_cow = !looking_at_cow;
        if (looking_at_cow)
        {
            auto look_at = getCameraLookAt();
            player.foward.x = look_at.x;
            player.foward.z = look_at.z;
        }
        actions.toggle_lock_cow = false;
    }

    // Checa cooldown
    double current_time = glfwGetTime();
    if (actions.fire && (current_time - last_fire_time) > 1.0)
    {
        last_fire_time = current_time;
        missiles.push_back(Missle(player.position, getCameraLookAt()));
    }
    // Desmarca a acao
    actions.fire = false;
    updateMissiles();
    updateCows();
    updateCollisions();
}

void World::updateCows()
{
    for (auto &cow : cows)
    {
        cow.update();
        cow.position.y = cow.height + terrain.getHeight(cow.position.x, cow.position.z);
    }
}

void World::updateMissiles()
{
    auto missile = missiles.begin();
    while (missile != missiles.end())
    {
        // TODO: Esse foward eh sempre unitario?
        missile->position += missile->foward * 0.05f;
        missile++;
    }
}

void World::updateCollisions()
{
    auto squaredDistance= [](glm::vec4 position, glm::vec4 position2)
    {
        return pow((position2.x - position.x), 2) +
               pow((position2.y - position.y), 2) +
               pow((position2.z - position.z), 2);
    };

    bool removed_cow = false;
    auto cow = cows.begin();
    while (cow != cows.end())
    {
        auto missile = missiles.begin();
        while (missile != missiles.end())
        {
            // Colisão esfera-esfera
            auto distance_centers = squaredDistance(cow->collisionSphereCenter(), missile->collisionSphereCenter());
            auto sum_radius = pow(cow->collisionSphereRadius() + missile->collisionSphereRadius(), 2);
            if (distance_centers < sum_radius)
            {
                // Hit
                // cout << "HIT" << endl;
                missiles.erase(missile++);
                cows.erase(cow++);
                removed_cow = true;
                score += 100; //aumenta score
                break;
            }
            else
            {
                missile++;
            }
        }
        if (!removed_cow)
        {
            ++cow;
        }
        removed_cow = false;

    }
}

glm::vec4 World::getCameraPosition()
{
    return player.position;
}

glm::vec4 World::getCameraLookAt()
{
    if (looking_at_cow)
    {
        auto v = closestCow().position - getCameraPosition();
        return v / norm(v);
    }
    else
    {
        return player.camera;
    }
}

glm::vec4 World::getCameraUp()
{
    return player.up;
    //return -crossproduct(getCameraLookAt(), player.foward);
}

Cow World::closestCow()
{

    auto squaredDistanceToPlayer = [this](glm::vec4 position)
    {
        return pow((this->player.position.x - position.x), 2) +
               pow((this->player.position.y - position.y), 2) +
               pow((this->player.position.z - position.z), 2);
    };


    return *std::min_element(cows.begin(), cows.end(), [squaredDistanceToPlayer](Cow cow1, Cow cow2) { return squaredDistanceToPlayer(cow1.position) < squaredDistanceToPlayer(cow2.position); } );
}


