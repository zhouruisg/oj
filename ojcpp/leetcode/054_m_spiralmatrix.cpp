//
// Created by Rui Zhou on 10/4/18.
//

/*
 * https://leetcode.com/problems/spiral-matrix/description/
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

 [
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int n = matrix.size()-1;
        int start = 0, end = n;
        while (start<end) {

            for (int i=start;i<end;i++)
                ret.push_back(matrix[start][i]);
            for (int i=start;i<end;i++)
                ret.push_back(matrix[i][n-start]);
            for (int i=start;i<end;i++)
                ret.push_back(matrix[end][n-i]);
            for (int i=start;i<end;i++)
                ret.push_back(matrix[n-i][start]);

            start++;end--;
        }
        if (start==end) {
            ret.push_back(matrix[start][end]);
        }
        return ret;
    }
};

DEFINE_CODE_TEST(054_spiral_matrix)
{
    Solution obj;
    {
        vector<vector<int>> m = {{ 5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
        VERIFY_CASE(PRINT_VEC(obj.spiralOrder(m)),"5 1 9 11 10 7 16 12 14 15 13 2 4 8 6 3");
    }
    {
        vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
        VERIFY_CASE(PRINT_VEC(obj.spiralOrder(m1)),"1 2 3 6 9 8 7 4 5");
    }
}
