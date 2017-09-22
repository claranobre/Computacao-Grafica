#ifndef LIGHTINGH
#define LIGHTINGH

#include "vec3.h"

class lighting{
public:
  vec3 intensity;
  vec3 direction;

  lighting(vec3 intensidade, vec3 direcao) : intensity(intensidade), direction(direcao){}

};

#endif
