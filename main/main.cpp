void a_julia();
void a_cameras();
void a_solids();
void a_indexing();
void a_instancing();
void a_lighting();
void a_materials();
void a_textures();
void a_local();
void a_mappers();
void a_distributed();
void a_smooth();
void a_bumpmappers();

#include <stdexcept>
#include <iostream>
#include <core/assert.h>
#include <core/vector.h>
using namespace rt;

int main(int argc, char* argv[])
{
    //a_julia();
    //a_cameras();  
    a_solids();
    a_indexing();
  
    return 0;
}