#ifndef METALH
#define METALH

class metal: public material{
public:
  virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const{
    vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected);
    attenuation = albedo;
    return (dot(scattered.direction(),rec.normal) >  0);
  }
  vec3 albedo;
};

#endif
