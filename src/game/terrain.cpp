#include "game/terrain.h"

Terrain::Terrain()
{

}

float Terrain::getHeight(float x, float z)
{
    // Mapeia o plano (-100,-100), (100, 100)  para a textura (0,0), (256, 256)
    int _x = ((x / 100.0f) + 1.0f) * 128.0f;
    int _z = ((z / 100.0f) + 1.0f) * 128.0f;
    if (_x < 0 || _x > length-1 || _z < 0 || _z > length-1)
    {
        printf("fail %d %d\n", _x, _z);
        return 0.0f;
    }
    // 3 canais * offset, pegamos qualquer canal da imagem
    return data[3 * (_x + length * _z)] * deformation_intensity;
}

void Terrain::deformTerrain(tinyobj::attrib_t &terrain)
{
    // Primeiro fazemos a leitura da imagem do disco
    stbi_set_flip_vertically_on_load(true);
    int width;
    int height;
    int channels;
    data = stbi_load("../../data/heightmap.jpg", &width, &height, &channels, 3);

    if ( data == NULL )
    {
        fprintf(stderr, "ERROR: Cannot open image file \n");
        return;
    }

    if (width != height)
    {
        fprintf(stderr, "ERROR: Image must be NxN \n");
        return;
    }
    length = width;


    printf("OK (%dx%d, %d).\n", width, height, channels);

    for (unsigned int i = 0; i < terrain.vertices.size(); i += 3)
    {
        // Mapeia o plano (-1,-1), (1,1) para a textura (0,0), (length, length)
        int x = (terrain.vertices[i] + 1.0f) * (length / 2.0f);
        int z = (terrain.vertices[i+2] + 1.0f) * (length / 2.0f);
        // 3 canais * offset, pegamos qualquer canal da imagem
        auto height = data[3 * (x + length * z)];
        // Y eh pra cima
        terrain.vertices[i+1] += height * deformation_intensity;
    }
}
