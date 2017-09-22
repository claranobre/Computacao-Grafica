#ifndef SPHONGH
#define SPHONGH

#include "hitable.h"

class phong: public hitable{
public:
  phong(){}
  virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
};

bool phong::hit(virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const){
  case kPhong:
  {
    vec3 diffuse = 0, specular = 0;
      for (uint32_t i = 0; i < lights.size(); ++i) {
        vec3 lightDir, lightIntensity;
        IsectInfo isectShad;
        lights[i]->illuminate(hitPoint, lightDir, lightIntensity, isectShad.tNear);

    bool vis = !trace(hitPoint + hitNormal * options.bias, -lightDir, objects, isectShad, kShadowRay);

    // compute the diffuse component
    diffuse += vis * isect.hit->albedo * lightIntensity * std::max(0.f, hitNormal.dot(-lightDir));

    // compute the specular component
    // what would be the ideal reflection direction for this light ray
    vec3 R = reflect(lightDir, hitNormal);
    specular += vis * lightIntensity * std::pow(std::max(0.f, R.dot(-dir)), isect.hit->n);
    }
    hitColor = diffuse * isect.hit->Kd + specular * isect.hit->Ks;
    //std::cerr << hitColor << std::endl;
    break;
  }
    default:
    break;
}
  else {
    hitColor = options.backgroundColor;
  }

  return hitColor;
}

#endif
