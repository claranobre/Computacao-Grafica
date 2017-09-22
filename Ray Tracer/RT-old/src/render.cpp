#include <iostream>
#include <fstream>
#include "../includes/camera.h"
#include "../includes/sphere.h"
#include "../includes/hitable_list.h"
#include "float.h"
#include "../includes/material.h"
#include "../includes/lighting.h"

using namespace std;

#ifdef TRADITIONAL_RT
Image Raytrace (Camera cam, Scene scene, int width, int height) {
  Image image = new Image(width, height);
  for(int i = 0; i < height; i++){
    for(int j = 0; i < width; j++){
      Ray ray = RayThruPixel (cam, i, j);
      Intersection hit = Intersect (ray, scene);
      image[i][j] = FindColor (hit);
    }
  }
  return image;
}
#endif

/*rgb color(const Ray & r_){
  rgb bottom(0.5,0.7,0);
  rpg top(1,1,1);

  return top;
}*/
vec3 random_in_unit_sphere(){
  vec3 p;
  do{
    p = 2.0 * vec3(drand48(),  drand48(), drand48()) - vec3(1,1,1);
  }while (dot(p,p) >= 1.0);
    return p;
}

vec3 color2(const ray& r, hitable *world){
  hit_record rec;
  if(world->hit(r,0.0, FLT_MAX, rec)){
    vec3 target = rec.p + rec.normal + random_in_unit_sphere();
    return 0.5 * color2(ray(rec.p, target-rec.p), world);
  }
  else{
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * vec3(1.0,1.0,1.0) + t * vec3(0.5, 0.7, 1.0);
  }
}

vec3 color(const ray& r, hitable *world){
  lighting luzinha(vec3 (0.8,0.8,0.8), vec3 (-8, 7, 0));
  vec3 cor(0,0,0);
  hit_record rec;
  if(world->hit(r,0.0, FLT_MAX, rec)){
    vec3 l = luzinha.direction;
    l.make_unit_vector();
    vec3 v = r.origin() - rec.p;
    v.make_unit_vector();
    vec3 h = l + v;
    h.make_unit_vector();

    float cosM = max(0.f, dot(rec.normal, l));
    float cosM2 = max(0.f, dot(rec.normal, h));
    //diffuse
    cor += rec.mate->Kd * luzinha.intensity * cosM;
    //specular
    cor += rec.mate->Ks * luzinha.intensity * pow(cosM2, rec.mate-> a);
    //luz ambinet ka * luzambiente
    return cor;
  }
  else{
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * vec3(1.0,1.0,1.0) + t * vec3(0.5, 0.7, 1.0);
  }
}

int main(){
  int nx = 600;
  int ny = 400;
  int ns = 1;

  material teste(vec3 (0.7,0.2,0.1), vec3 (1,1,1), vec3(0.1, 1, 0.1), 64);
  //lighting luzinha(vec3 (1,1,1), vec3 (-8, 7, 0));

  ofstream arquivo;
  arquivo.open("teste.ppm");

  arquivo << "P3\n" << nx << " " << ny << "\n 255\n";

  vec3 lower_left_corner(-2.0, -1.0, -1.0);
  vec3 horizontal(4.0, 0.0, 0.0);
  vec3 vertical(0.0, 2.0, 0.0);
  vec3 origin(0.0,0.0,0.0);

  hitable *list[2];
  list[0] = new sphere(vec3(0.3 ,0,-1), 0.5, &teste);
  list[1] = new sphere(vec3(0,-100.5,-1), 100, &teste);

  hitable *world = new hitable_list(list,2);
  camera cam;

  for(int j = ny - 1; j >= 0; j--){
    for(int i = 0; i < nx; i++){
      vec3 col(0,0,0);
      for(int s = 0; s < ns; s++){
        float u = float(i + drand48()) / float(nx);
        float v = float(j + drand48()) / float(ny);
        ray r = cam.get_ray(u,v);
        //vec3 p = r.point_at_parameter(2.0);
        col += color(r,world);
      }
      col /= float(ns);

      int ir = int(255.99 * col[0]);
      int ig = int(255.99 * col[1]);
      int ib = int(255.99 * col[2]);

      arquivo << ir << " " << ig << " " << ib << "\n";
    }
  }
  arquivo.close();
}
