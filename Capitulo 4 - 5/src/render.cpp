#include <iostream>
#include <fstream>
#include "../includes/sphere.h"
#include "../includes/hitable_list.h"
#include "float.h"

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

vec3 color(const ray& r, hitable *world){
  hit_record rec;
  if(world->hit(r,0.0, FLT_MAX, rec)){
    return 0.5 * vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
  }
  else{
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * vec3(1.0,1.0,1.0) + t * vec3(0.5, 0.7, 1.0);
  }
}

int main(){
  int nx = 1200;
  int ny = 600;

  ofstream arquivo;
  ofstream arquivo2;
  arquivo.open("colored_normals.ppm");
  //arquivo2.open("depht_map.ppm")

  arquivo << "P3\n" << nx << " " << ny << "\n 255\n";
  //arquivo2 << "P3\n" << nx << " " << ny << "\n 255\n";

  vec3 lower_left_corner(-2.0, -1.0, -1.0);
  vec3 horizontal(4.0, 0.0, 0.0);
  vec3 vertical(0.0, 2.0, 0.0);
  vec3 origin(0.0,0.0,0.0);
 /*
 Esferas = { cemter, radius }
  { point3(0,-100.5,-3), 99.f },
   { point3( 0.3 , 0 , -1 ), 0.4 },
   { point3( 0 , 1 , -2 ), 0.6 },
    { point3(-0.4 , 0 , -3 ), 0.7 }
    max_depth = 4.f foreground_depth = (0,0,0) background_depth = (1,1,1)
    */
  hitable *list[4];
  list[0] = new sphere(vec3(0.3 ,0,-1), 0.4);
  list[1] = new sphere(vec3(0,-100.5,-3), 99.f);
  list[2] = new sphere(vec3(0,1,-2), 0.6);
  list[3] = new sphere(vec3(-0.4, 0, -3), 0.7);

  hitable *world = new hitable_list(list,4);

  for(int j = ny - 1; j >= 0; j--){
    for(int i = 0; i < nx; i++){
      float u = float(i) / float(nx);
      float v = float(j) / float(ny);
      ray r(origin, lower_left_corner + u * horizontal + v * vertical);
      vec3 p = r.point_at_parameter(2.0);
      vec3 col = color(r, world);

      int ir = int(255.99 * col[0]);
      int ig = int(255.99 * col[1]);
      int ib = int(255.99 * col[2]);

      arquivo << ir << " " << ig << " " << ib << "\n";
    }
  }
  arquivo.close();
}
