// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

TEST(test_fill_edge) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 1;
  const int height = 1;
  const int value = 8;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_matrix_height){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  ASSERT_EQUAL(Matrix_height(mat), 5);
  delete mat;
}

TEST(test_matrix_width){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  ASSERT_EQUAL(Matrix_width(mat), 3);
  delete mat;
}

TEST(test_matrix_row){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  int *ptr = Matrix_at(mat, 2, 0);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
  delete mat;
}

TEST(test_matrix_column){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  int *ptr = Matrix_at(mat, 2, 0);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 0);
  delete mat;
}

TEST(test_matrix_at){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 4);
  int *ptr = Matrix_at(mat, 2, 0);
  ASSERT_EQUAL(*ptr, 4);
  delete mat;
}

TEST(test_matrix_fill_border){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  Matrix_fill_border(mat, value);
  for (int i = 0; i < Matrix_height(mat); ++i){
    for (int j = 0; j < Matrix_width(mat); ++j){
      if (i == 0 || j == 0 || i == height - 1 || j == width - 1){
        ASSERT_EQUAL(*Matrix_at(mat,i,j),8);
      }else{
        ASSERT_EQUAL(*Matrix_at(mat,i,j),0);
      }
    } 
  }
  delete mat;
}

TEST(test_matrix_max){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  Matrix_fill_border(mat, value);
  ASSERT_EQUAL(Matrix_max(mat), 8);
  delete mat;
}

TEST(edge2_matrix_max){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 4);
  ASSERT_EQUAL(Matrix_max(mat), 4);
  delete mat;
}

TEST(test_min_matrix_of_col){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  Matrix_fill_border(mat, value);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 3), 1);
  delete mat;
}

TEST(test_min_matrix_of_value){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 0);
  Matrix_fill_border(mat, value);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 3), 0);
  delete mat;
}

TEST(edge_test_matrix_print){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 1, 1);

    *Matrix_at(mat, 0, 0) = 42;
    ostringstream expected;
    expected << "1 1\n"
             << "42 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}

TEST(test_const_int_matrix_at){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    const int width = 3;
    const int height = 5;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, 4);
    const Matrix *cmat = mat;
    const int *ptr = Matrix_at(cmat, 2, 0);
    ASSERT_EQUAL(*ptr, 4);
    delete mat;
}

TEST(test_matrix_init){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory

    const int width = 3;
    const int height = 5;
    Matrix_init(mat, width, height);
    ASSERT_EQUAL(Matrix_height(mat), 5);
    ASSERT_EQUAL(Matrix_width(mat), 3);
    delete mat;
}

TEST(edge1_test_max){
    Matrix *mat = new Matrix;
    const int width = 3;
    const int height = 5;
    const int max_value = 99;
    Matrix_init(mat, width, height);
    for (int r = 0; r < height; ++r){
        for (int c = 0; c < width; ++c){
            *Matrix_at(mat, r, c) = r * width + c;
        }
    }
    *Matrix_at(mat, 4, 2) = max_value;
    ASSERT_EQUAL(Matrix_max(mat), max_value);
    delete mat;
    
}

TEST(edge1_test_fill_border){
    Matrix *mat1 = new Matrix;
    Matrix *mat2 = new Matrix;
    const int width = 2;
    const int height = 2;
    Matrix_init(mat1, width, height);
    Matrix_init(mat2, width, height);
    Matrix_fill(mat2, 1);
    Matrix_fill(mat1, 0);
    Matrix_fill_border(mat1, 1);
    ASSERT_TRUE(Matrix_equal(mat1, mat2));
    delete mat1;
    delete mat2;
}

TEST(edge2_test_fill_border){
    Matrix *mat1 = new Matrix;
    Matrix *mat2 = new Matrix;
    const int width = 1;
    const int height = 1;
    Matrix_init(mat1, width, height);
    Matrix_init(mat2, width, height);
    Matrix_fill(mat2, 1);
    Matrix_fill(mat1, 0);
    Matrix_fill_border(mat1, 1);
    ASSERT_TRUE(Matrix_equal(mat1, mat2));
    delete mat1;
    delete mat2;
}

TEST(edge3_test_fill_border){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory

    const int width = 3;
    const int height = 5;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, 4);
    Matrix_fill_border(mat, 8);
    for (int c = 0; c < Matrix_width(mat); ++c){
        ASSERT_EQUAL(*Matrix_at(mat, 0, c), 8);
        ASSERT_EQUAL(*Matrix_at(mat, 4, c), 8);
    }
    for (int r = 0; r < Matrix_height(mat); ++r){
        ASSERT_EQUAL(*Matrix_at(mat, r, 0), 8);
        ASSERT_EQUAL(*Matrix_at(mat, r, 2), 8);
    }
    delete mat;
}

TEST(edge4_test_fill_border){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory

    const int width = 3;
    const int height = 5;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, 4);
    Matrix_fill_border(mat, 8);
    ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 8);
    delete mat;
}

TEST(edge5_test_fill_border){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory

    const int width = 3;
    const int height = 5;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, 4);
    Matrix_fill_border(mat, 8);
    ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 4);
    delete mat;
}

TEST(edge1_test_matrix_of_col){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 3), 0);
  delete mat;
}

TEST(edge1_test_matrix_of_value){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 3), 0);
  delete mat;
}

TEST(edge2_test_matrix_of_col){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 2;
  const int height = 2;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 2), 0);
  delete mat;
}

TEST(edge2_test_matrix_of_value){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 2), 0);
  delete mat;
}

TEST(edge3_test_matrix_of_col){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 1;
  const int height = 1;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 1), 0);
  delete mat;
}

TEST(edge3_test_matrix_of_value){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 0);
  delete mat;
}

TEST(edge4_test_matrix_of_col){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 5;
  const int height = 3;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 1, 3), 1);
  delete mat;
}

TEST(edge4_test_matrix_of_value){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 5;
  const int height = 3;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 0);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 1, 3), 8);
  delete mat;
}

TEST(edge5_test_matrix_of_col){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 5;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 4);
  *Matrix_at(mat, 1, 3) = 0;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 5), 3);
  delete mat;
}

TEST(edge5_test_matrix_of_value){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 5;
  const int height = 5;
  const int value = 8;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, 4);
  *Matrix_at(mat, 1, 3) = 0;
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 5), 0);
  delete mat;
}

TEST(edge_test_matrix_at){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, 4);
  int *ptr = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(*ptr, 4);
  delete mat;
}

TEST(edge_test_const_int_matrix_at){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory

    const int width = 3;
    const int height = 5;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, 4);
    const Matrix *cmat = mat;
    const int *ptr = Matrix_at(cmat, 0, 0);
    ASSERT_EQUAL(*ptr, 4);
    delete mat;
}

TEST(test_matrix_print1){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 2, 2);

    Matrix_fill(mat, 8);
    ostringstream expected;
    expected << "2 2\n"
             << "8 8 \n"
             << "8 8 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}


TEST(test_matrix_print2){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 3);

    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, 8);
    ostringstream expected;
    expected << "3 3\n"
             << "8 8 8 \n"
             << "8 0 8 \n"
             << "8 8 8 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}

TEST(test_matrix_print4){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 2, 2);

    Matrix_fill(mat, 0);
    *Matrix_at(mat, 0, 0) = 8;
    ostringstream expected;
    expected << "2 2\n"
             << "8 0 \n"
             << "0 0 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}

TEST(test_matrix_print5){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 2, 2);

    Matrix_fill(mat, 0);
    *Matrix_at(mat, 1, 0) = 8;
    ostringstream expected;
    expected << "2 2\n"
             << "0 0 \n"
             << "8 0 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}


TEST(test_matrix_print3){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 2, 2);

    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, 8);
    ostringstream expected;
    expected << "2 2\n"
             << "8 8 \n"
             << "8 8 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}

TEST(edeg1_test_matrix_row){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  int *ptr = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 0);
  delete mat;
}

TEST(edge1_test_matrix_column){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  int *ptr = Matrix_at(mat, 0, 0);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 0);
  delete mat;
}

TEST(edge2_test_matrix_row){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  int *ptr = Matrix_at(mat, 4, 2);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 4);
  delete mat;
}

TEST(edge2_test_matrix_column){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  Matrix_init(mat, width, height);
  int *ptr = Matrix_at(mat, 4, 2);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 2);
  delete mat;
}

TEST(test_matrix_inAll){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 8, 8);

    ASSERT_EQUAL(Matrix_width(mat), 8);
    ASSERT_EQUAL(Matrix_height(mat), 8);

    Matrix_fill(mat, 1);

    int *ptr = Matrix_at(mat, 3, 5);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 3);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 5);
    ASSERT_EQUAL(*ptr, 1);
    *ptr = 4;

    const int *cptr = Matrix_at(mat, 3, 5);
    ASSERT_EQUAL(*cptr, 4);

    Matrix_fill_border(mat, 2);
    ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 2);

    ASSERT_EQUAL(Matrix_max(mat), 4);

    delete mat;
}

TEST(test_matrix_print_inAll1){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, 1);
    *Matrix_at(mat, 0, 0) = 2;
    *Matrix_at(mat, 1, 1) = 3;
    *Matrix_at(mat, 2, 1) = 4;
    ostringstream expected;
    expected << "3 3\n"
             << "2 1 1 \n"
             << "1 3 1 \n"
             << "1 4 1 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}

TEST(test_matrix_print_inAll2){
    Matrix *mat = new Matrix;
    Matrix_init(mat, 4, 4);
    Matrix_fill(mat, 1);
    Matrix_fill_border(mat, 3);
    *Matrix_at(mat, 0, 0) = 2;
    *Matrix_at(mat, 2, 1) = 4;
    ostringstream expected;
    expected << "4 4\n"
             << "2 3 3 3 \n"
             << "3 1 1 3 \n"
             << "3 4 1 3 \n"
             << "3 3 3 3 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}



TEST(test_siez1_edge_min){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory

    const int width = 1;
    const int height = 1;
    const int value = 8;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 1), 0);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 1), 8);
    delete mat;
}

TEST(test_border_edge){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    const int width = 3;
    const int height = 3;
    const int value = 1;
    Matrix_init(mat, width, height);
    Matrix_fill(mat, value);
    Matrix_fill_border(mat, 4);
    
    ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 1);
    delete mat;
}

TEST(edge_test_max_from_lec) {
    Matrix *mat = new Matrix;
    const int width = 3;
    const int height = 5;
    const int max_value = 99;
    Matrix_init(mat, width, height);
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            *Matrix_at(mat, row, col) = row * width + col;
        }
    }
    *Matrix_at(mat, 4, 2) = max_value;
    ASSERT_EQUAL(Matrix_max(mat), max_value);
    delete mat;
}


TEST(new_test1){
  Matrix *mat = new Matrix;
  const int height = 3;
  const int width = 5;
  const int value = 5;
  const int border_value = 10;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, border_value);
  *Matrix_at(mat, 1, 2) = -5;
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 5), 10); 
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 5), -5); 
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 2, 5), -5);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 3, 5), 5);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 2), 5);
  delete mat;
}

TEST(new_test2){
  Matrix *mat = new Matrix;
  const int height = 3;
  const int width = 5;
  const int value = 5;
  const int border_value = 10;
  Matrix_init(mat, width, height);
  Matrix_fill(mat, value);
  Matrix_fill_border(mat, border_value);
  *Matrix_at(mat, 1, 2) = -5;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 5), 0); 
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 5), 2); 
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 2, 5), 2);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 3, 5), 3);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, 2), 1);
  delete mat;
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
