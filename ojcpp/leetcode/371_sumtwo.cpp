//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/sum-of-two-integers/description/
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
 */

#include <codech/codech_def.h>

class Solution {
public:
    int getSum(int a, int b) {
        return 0;
    }
};

DEFINE_CODE_TEST(371_twosum)
{
    Solution obj;
    VERIFY_CASE(obj.getSum(1,2),3);
}



