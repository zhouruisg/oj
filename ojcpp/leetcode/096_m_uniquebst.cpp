//
// Created by rui.zhou on 3/9/2019.
//

/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   实际上就是一个DP问题
   095也可以用DP来解决的
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[1000]={0};
        dp[0]=1;
        dp[1]=1;
        if (n<2)
            return dp[n];
        for (int i=2;i<=n;i++) {
            for (int j=0;j<i;j++) {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

DEFINE_CODE_TEST(096_uniquebst)
{
    Solution obj;
    {
        VERIFY_CASE(obj.numTrees(3),5);
    }
}
