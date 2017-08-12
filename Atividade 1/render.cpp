#include <iostream>
#include <fstream>

#define NAME
#define TYPE
#define CODIFICATION
#define WIDTH
#define HEIGHT
#define UPPER_LEFT
#define LOWER_LEFT
#define UPPER_RIGHT
#define LOWER_RIGHT

using namespace std;

int main(int argc, char** argv){
  char letter;
  FILE *ofs_file = fopen( argv[1], "r" );
  string file_name("background.ppm");
  ofstream ofs_file(file_name, ios::out | ios::ascii);

  if(not ofs_file.is_open()){
    cerr <<  ">> Failed with attemping to open image file \'" << file_name >
    return EXIT_FAILURE;
  }else{
    while (ofs_file.get(letter)){
      cout << letter;
    }
    letter.close();
  }

  int n_cols = 200;
  int n_rows = 100;

  ofs_file << "P3\n" << n_cols << " " << n_rows << "\n255\n";

  for(int j = n_rows - 1; j>= 0; j--){
    for(int i = 0; i < n_cols; i++){
      float r = float(i) / float(n_cols);
      float g = float(j) / float(n_rows);
      float b = 0.2;

      int ir = int(255.99 * r);
      int ig = int(255.99 * g);
      int ib = int(255.99 * b);

      ofs_file << ir << " " << ig << " " << ib << "\n";
    }
  }
  ofs_file.close();
  return 0;

  /*ofs_file << "P6\n";
           << n_cols << " " << n_rows << "\n";
           << "255\n";

  char buffer[3 * n_cols * n_rows];
  size_t n_pixels(0);*/
}
