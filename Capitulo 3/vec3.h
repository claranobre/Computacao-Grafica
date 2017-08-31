#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

//namespace utility{
class vec3{
public:
  typedef float value_type_t;
  enum field_t: int {X=0, Y=1, Z=2, R=0, G=1, B=2};

  vec3(value_type_t e0=0.f, value_type_t e1=0.f, value_type_t e2=0.f)
      : e{ e0, e1, e2_}

  inline value_type_t x() const {return e[X];}
  inline value_type_t y() const {return e[Y];}
  inline value_type_t z() const {return e[Z];}
  inline value_type_t r() const {return e[R];}
  inline value_type_t g() const {return e[G];}
  inline value_type_t b() const {return e[B];}

  /* inline float operator[](int i) const {return e[i];}
  inline float& operator[](int i){return e[i]; };*/

  inline value_type_t operator[] (size_t x) const {return e[x];}
  inline value_type_t& operator[] (size_t x) {return e[x];}

  inline const vec3& operator+() const { return *this; }
  inline vec3 operator-() const {return vec3(-e[X], -e[Y], -e[Z]);}

  /*inline vec3 operator+(const vec3 &v1, const vec3 &v2){
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
  }
  inline vec3 operator-(const vec3 &v1, const vec3 &v2){
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
  }
  inline vec3 operator*(const vec3 &v1, const vec3 &v2){
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
  }
  inline vec3 operator/(const vec3 &v1, const vec3 &v2){
    return vec3(v1;e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
  }*/

  inline vec3& operator+=(const vec3&);
  inline vec3& operator-=(const vec3&);
  inline vec3& operator*=(const vec3&);
  inline vec3& operator/=(const vec3&);
  inline vec3& operator*=(const value_type_t);
  inline vec3& operator/=(const value_type_t);

  inline value_type_t length() const {return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
  inline value_type_t squared_lenght() const {return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }
  inline void make_unit_vector();
//};

/*typedef vec3 color;
typedef vec3 offset;
typedef vec3 point3;*/

//}

//#include "vec3.inl"

  // Geometric operations
  inline float dot(const vec3 &v1, const vec3 &v2){
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
  }
  inline vec3 cross(const vec3 &v1, const vec3 &v2){
    return vec3( (v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
                 (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
                 (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
  }

  inline vec3 unit_vector(vec3 v){
    return (v/v.length());
  }

  float e[3];
};

#include "vec3.inl"
#endif
