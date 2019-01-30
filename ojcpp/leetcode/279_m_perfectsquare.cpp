//
// Created by rui zhou on 30/01/19.
//

/*
 * https://leetcode.com/problems/perfect-squares/
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

 */

#include <codech/codech_def.h>

class Solution {
public:
    int numSquares(int n) {
        int count=0;
        while (n>0) {
            r = sqrt(n);
            n=n-r*r;
            count++;
        }
        return count;
    }
};

DEFINE_CODE_TEST(073_setmatrixzero)
{
    Solution obj;
    {
        //VERIFY_CASE(PRINT_MATRIX(m),"1 0 1 0 0 0 1 0 1");
    }
}