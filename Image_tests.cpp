// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_print_basic1) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel brown = {124, 63, 63};
  const Pixel black = {0, 0, 0};
  const Pixel grey = {100, 100, 100};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 5, 2);
  Image_set_pixel(img, 0, 0, white);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 0, 2, green);
  Image_set_pixel(img, 0, 3, white);
  Image_set_pixel(img, 0, 4, black);
  Image_set_pixel(img, 1, 0, brown);
  Image_set_pixel(img, 1, 1, brown);
  Image_set_pixel(img, 1, 2, black);
  Image_set_pixel(img, 1, 3, grey);
  Image_set_pixel(img, 1, 4, blue);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n5 2\n255\n";
  correct << "255 255 255 0 255 0 0 255 0 255 255 255 0 0 0 \n";
  correct << "124 63 63 124 63 63 0 0 0 100 100 100 0 0 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_image) {
  Image *img = new Image;
  ifstream ins;
  ins.open("dog.ppm");
  //ifs.open("dog.ppm");
  Image_init(img, ins);
  int height = Image_height(img);
  int width = Image_width(img);
  for(int i = 0; i < height - 1; i++) {
    for(int j = 0; j < width - 1; j++) {
      Image_get_pixel(img, i ,j);
    }
  }
  ostringstream s;
  Image_print(img, s);
  ins.close();

  // Correct output
  ostringstream correct;
  correct <<"P3\n5 5\n255\n";
  correct << "0 0 0 0 0 0 255 255 250 0 0 0 0 0 0 \n";
  correct << "255 255 250 126 66 0 126 66 0 126 66 0 255 255 250 \n";
  correct << "126 66 0 0 0 0 255 219 183 0 0 0 126 66 0 \n";
  correct << "255 219 183 255 219 183 0 0 0 255 219 183 255 219 183 \n";
  correct << "255 219 183 0 0 0 134 0 0 0 0 0 255 219 183 \n";
  ASSERT_EQUAL(s.str(), correct.str());
  delete img;
  //ins.open("dog.ppm");



}
TEST(test_image2) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel purple = {163, 73, 64};

  Image_init(img, 2, 3);
  Image_fill(img, purple);

  ostringstream s;
  Image_print(img, s);

  ostringstream correct;
  correct << "P3\n2 3\n255\n";
  correct << "163 73 64 163 73 64 \n";
  correct << "163 73 64 163 73 64 \n";
  correct << "163 73 64 163 73 64 \n";
  ASSERT_EQUAL(s.str(), correct.str());
  delete img;
}

TEST(test_image3){
  Image *img = new Image;
  Image_init(img, 3 , 8);
  ASSERT_EQUAL(Image_width(img) , 3);
  ASSERT_EQUAL(Image_height(img) , 8);
  delete img;
}

TEST(test_image4){
  Image *img = new Image;
  Image_init(img, 3 , 8);
  Pixel color;
  color.b = 100;
  color.r = 100;
  color.g = 100;
  Image_set_pixel(img,0,0,color);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img,0,0),color));
  delete img;
}

TEST(test_image5){
  Image *img = new Image;
  Image_init(img, 3 , 8);
  Pixel color;
  color.b = 100;
  color.r = 100;
  color.g = 100;
  Image_fill(img,color);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img,1,1),color));
  delete img;
}



// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
