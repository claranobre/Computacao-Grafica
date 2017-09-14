#include <blinn_phong_mat.h>

public BlinnPhongMaterial(const rgb $ka_, const rgb &kd_, const rgb &ks_, real_type pe_){}

public virtual bool scatter(const Ray &r_in, const HitRecord &hr_, utility::vec3 &att_, Ray &r_scattered_){}

vec3 m_ka;
vec3 m_kd;
vec3 m_ks;
real_type m_phong_exponent;

rt::BlinnPhongMaterial::BlinnPhongMaterial	(
const rgb & 	ka_,
const rgb & 	kd_,
const rgb & 	ks_,
real_type 	pe_
)

virtual bool rt::BlinnPhongMaterial::scatter	(	const Ray & 	r_in_,
const HitRecord & 	hr_,
utility::vec3 & 	att_,
Ray & 	r_scattered_
)

vec3 rt::BlinnPhongMaterial::m_ka
vec3 rt::BlinnPhongMaterial::m_kd
vec3 rt::BlinnPhongMaterial::m_ks
real_type rt::BlinnPhongMaterial::m_phong_exponent
