//
// Created by rui zhou on 28/03/18.
//


/*
 * https://leetcode.com/problems/rotate-image/description/
 * You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

 0,0 -> 2,0;
 1,0 -> 2,1;
 2,0 -> 2,2

 i,j -> n-j,i



 */

#include <codech/codech_def.h>
#include <iostream>
#include <sstream>
#include <codech/codech_util.h>

using namespace std;
using namespace CODECH;

void printmatrix(vector<vector<int>> &m) {
    for (auto &row : m){
        for (auto &v : row) {
            cout << v << " ";
        }
        cout << endl;
    }
}

string verifymatrix(vector<vector<int>> &m) {
    stringstream ss;
    for (auto &row : m){
        for (auto &v : row) {
            ss << v << " ";
        }
    }
    return trim(ss.str());
}

class Solution {
public:
    void ms(int &x, int &y) {
        // cout << "swap " << x << " -> " << y << endl;
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int start = 0, end = n;
        while (start<end) {
            for (int i=start;i<end;i++) {
                swap(matrix[start][i], matrix[i][n-start]); // A->B
                swap(matrix[start][i], matrix[end][n-i]);  // B->C
                swap(matrix[start][i], matrix[n-i][start]);  //C(A)->D
            }
            start++;end--;
        }
    }
};



DEFINE_CODE_TEST(048_rotateimage)
{
    Solution obj;
    {
        vector<vector<int>> i1 = {{ 4,8},{3,6}};
        obj.rotate(i1);
        VERIFY_CASE(verifymatrix(i1),"3 4 6 8 ");
    }

    {
        vector<vector<int>> i1 = {{1,2,3},{4,5,6},{7,8,9}};
        obj.rotate(i1);
        VERIFY_CASE(verifymatrix(i1),"7 4 1 8 5 2 9 6 3");
    }

    {
        vector<vector<int>> i1 = {{ 5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
        obj.rotate(i1);
        VERIFY_CASE(verifymatrix(i1),"15 13 2 5 14 3 4 1 12 6 8 9 16 7 10 11");
    }
}