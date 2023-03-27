// Project UID af1f95f547e44c8ea88730dfb185559d
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Image.h"
#include "processing.h"
using namespace std;
int main(int argc, char *argv[]){
    if (argc != 4 && argc != 5){
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return -1;
    }
    string input_filename = argv[1];
    string output_filename = argv[2];
    ifstream input;
    input.open(input_filename);
    if (!input.is_open()){
        cout << "Error opening file: " << input_filename << endl;
        return -1;
    }
    Image *img = new Image;
    Image_init(img, input);
    int width = atoi(argv[3]);
    if (width <= 0 || width > img -> width){
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return -1;
    }
    if (argc == 4){
        seam_carve_width(img, width);
    }else{
        int height = atoi(argv[4]);
        if (height <= 0 || height > img -> height){
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return -1;
        }
        seam_carve(img, width, height);
    }
    ofstream output;
    output.open(output_filename);
    if (!output.is_open()){
        cout << "Error opening file: " << output_filename << endl;
        return -1;
    }
    Image_print(img, output);
    delete img;
    return 0;
}



