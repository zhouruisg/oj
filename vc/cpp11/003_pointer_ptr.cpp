//
// Created by rui.zhou on 2/25/2019.
//

#include <codech/codech_def.h>
using namespace std;

namespace c11 {
    void multi_dimension_array() {

        int arr[3][2]={{1,2},{3,4},{5,6}};
        for (int i=0;i<3;i++) {
            for (int j=0;j<2;j++) {
                cout << &arr[i][j] << endl;
            }
        }
        //int arr[][2] = {(1,2,3),(4,5,6)}  这种方式实质上是逗号运算符，等于{3,6}
    }

    void double_ptr() {
        int **board;
        board = new int*[3]; // dynamic array (size 10) of pointers to int

        for (int i = 0; i < 3; ++i) {
            board[i] = new int[2];
            // each i-th pointer is now pointing to dynamic array (size 10) of actual int values
        }

        for (int i = 0; i < 3; ++i) {   // for each row
            for (int j = 0; j < 2; ++j) { // for each column
                board[i][j] = i*10+j;
                cout << &board[i][j] << endl;
            }
        }

    }
}



DEFINE_CODE_TEST(c11_003_pointer)
{
    //c11::test_string();
    c11::multi_dimension_array();
    c11::double_ptr();
}
