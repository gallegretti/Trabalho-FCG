#include "game/missle.h"

Missle::Missle(glm::vec4 position, glm::vec4 foward)
{
    this->position = position;
    this->foward = foward;
    // O modelo do missel esta apontando para -x,
    // entao calculamos a matrix de rotacao da posicao original
    // p/ a orientacao dessa instancia
    auto c = crossproduct(this->foward, glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
    float d = dotproduct(this->foward, glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f));
    float Angle = acos( d );
    this->rotation_matrix = Matrix_Rotate(-Angle, c);

}
