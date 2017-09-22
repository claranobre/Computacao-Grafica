#ifndef MATERIALH
#define MATERIALH
#include "vec3.h"

class material{
public:
  vec3 Kd; // phong model diffuse weight
  vec3 Ks; // phong model specular weights
  vec3 Ka;   // phong ambient exponent
  float a;
  /*material(){
    Kd = vec3 (0.1, 0.1, 0.1);
    Ks = vec3 (0.4, 0.4, 0.4);
    Ka = vec3(0.1, 1, 0.1);
    a = float(2.1);
  }*/
  material(vec3 k_d, vec3 k_s, vec3 k_a,float a_a): Kd(k_d), Ks(k_s), Ka(k_a), a(a_a) {}
};

#endif
