#ifndef MATERIALH
#define MATERIALH
#include "vec3.h"

class material{
public:
  //virtual bool scatter(const ray& r_in, hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
  vec3 Kd; // phong model diffuse weight
  vec3 Ks; // phong model specular weights
  vec3 Ka;   // phong ambient exponent
  float a;

  material(vec3 k_d, vec3 k_s, vec3 k_a,float a_a): Kd(k_d), Ks(k_s), Ka(k_a), a(a_a) {}
};

#endif
