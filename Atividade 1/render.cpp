#include <iostream>
#include <fstream>
#include <map>
#include <string>

#define NAME "NAME"
#define TYPE "TYPE"
#define CODIFICATION "CODIFICATION"
#define WIDTH "WIDTH"
#define HEIGHT "HEIGHT"
#define UPPER_LEFT "UPPER_LEFT"
#define LOWER_LEFT "LOWER_LEFT"
#define UPPER_RIGHT "UPPER_RIGHT"
#define LOWER_RIGHT "LOWER_RIGHT"
#define MAX 255
#define NB_CHANNEL 3

using namespace std;

int main(int argc, char** argv){
  map<string, string> properties = { {NAME, ""},
                                     {TYPE, ""},
                                     {CODIFICATION, ""},
                                     {SIZE_HEIGHT, ""},
                                     {SIZE_WIDTH, ""},
                                     {UPPER_LEFT, ""},
                                     {UPPER_RIGHT, ""},
                                     {LOWER_LEFT, ""},
                                     {LOWER_RIGHT, ""}
                                  };
string format = "P6";
//Read the file
  if(argc < 2){
    cerr << "Input" << '\n';
  }
  string::string file_name = argv[1];
  ifstream file(file_name.c_str(), ifstream::in);
  string content = "";
  if(file.is_open()){
    while(!file.eof()){
      getline(file, content);
      istringstream field(content);
      int limiter = content.find_first_of("=");
      if(limiter != string::npos){
        string key = content.substr(0,limiter);
        string val = content.substr(limiter + 1, content.length());
        if(properties.find(key) == properties.end()){
        }else{
          properties[key] = val;
        }
      }
    }
  } else{
    cerr << "Not a correct file: " << file_name << '\n';
  }

  int n_cols(stoi(properties[SIZE_WIDTH]));
  int n_rows(stoi(properties[SIZE_HEIGHT]));
  int size = n_cols * n_rows;

  //TODO: Treat TYPE/CODIFICATION
  bool is_binary;
  if (properties[CODIFICATION] == "binary"){
    is_binary = true;
  }
  else if (properties[CODIFICATION] == "ascii") {
    is_binary = false;
  } else{
    cerr << "Codification not accepted (yet)" << endl;
  }

  for(int j = n_rows - 1; j>= 0; j--){
    for(int i = 0; i < n_cols; i++){
      float r = float(i) / float(n_cols);
      float g = float(j) / float(n_rows);

      int ir = int(255.99 * r);
      int ig = int(255.99 * g);
      int ib = int(255.99 * b);
    }
    image << format << "\n" << n_cols << " " << n_rows << "\n" << MAX << "\n";
    image.close();
  }
  return 0;
}
