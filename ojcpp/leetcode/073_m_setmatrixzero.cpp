//
// Created by rui.zhou on 1/25/2019.
//

/*https://leetcode.com/problems/set-matrix-zeroes/
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 */
#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        vector<vector<int>> d = matrix;
        int m=matrix.size();
        int n=matrix[0].size();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (matrix[i][j]==0) {
                    for (int k=0;k<n;k++) {
                        d[i][k] = 0;
                    }
                    for (int k=0;k<m;k++) {
                        d[k][j] = 0;
                    }
                }
            }
        }
        matrix = d;
    }
};

DEFINE_CODE_TEST(073_setmatrixzero)
{
    Solution obj;
    {
        vector<vector<int>> m = {{ 1,1,1},{1,0,1},{1,1,1}};
        obj.setZeroes(m);
        VERIFY_CASE(PRINT_MATRIX(m),"1 0 1 0 0 0 1 0 1");

    }
}