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
 实际上没有做到in-place
 如果识别0是原来就有的还是被改变的
 TODO 更好的方法？
 */
#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

namespace {
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
    //方法2 - 先转为 特殊字符？问题是不一定允许特殊字符
    //方法3，相当于把0挪到第一列第一行来作为保留信息。

    class Solution1 {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            int i, j;

            //先标记第一行和第一列是否有0
            bool firstRow = false, firstCol = false;
            for (j = 0; j < n; j++) {
                if (0 == matrix[0][j]) {
                    firstRow = true;
                    break;
                }
            }
            for (i = 0; i < m; i++) {
                if (0 == matrix[i][0]) {
                    firstCol = true;
                    break;
                }
            }

            //从第二行第二列还是遍历，如果遇到0，则把它所在行和列的第一个值设为0
            for (i = 1; i < m; i++) {
                for (j = 1; j < n; j++) {
                    if (0 == matrix[i][j]) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            //把第一列的0所在行都设为0，把第一行的0所在列都设为0
            for (i = 1; i < m; i++) {
                if (0 == matrix[i][0]) {
                    for (j = 1; j < n; j++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            for (j = 1; j < n; j++) {
                if (0 == matrix[0][j]) {
                    for (i = 1; i < m; i++) {
                        matrix[i][j] = 0;
                    }
                }
            }

            //根据标记决定第一行和第一列是否全设为0
            if (firstRow) {
                for (j = 0; j < n; j++) {
                    matrix[0][j] = 0;
                }
            }
            if (firstCol) {
                for (i = 0; i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
        }
    };
}


DEFINE_CODE_TEST(073_setmatrixzero)
{
    Solution1 obj;
    {
        vector<vector<int>> m = {{ 1,1,1},{1,0,1},{1,1,1}};
        obj.setZeroes(m);
        VERIFY_CASE(PRINT_MATRIX(m),"1 0 1 0 0 0 1 0 1");

    }
}