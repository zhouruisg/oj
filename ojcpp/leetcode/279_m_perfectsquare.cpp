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

 class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            if((int) Math.pow((int) Math.sqrt(i), 2) == i){
                dp[i] = 1;
            }
            else{
                int sqrt = (int) Math.sqrt(i);
                int j = 1;
                dp[i] = i;
                while(j <= sqrt){
                    dp[i] = Math.min(dp[i], 1 + dp[i - (int) Math.pow(j, 2)]);;
                    j++;
                }
            }
        }
        return dp[n];
    }
}

思路，使用DP, 记录dp[i]为i所在perfect square个数


 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int numSquares0(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int num = 1; num*num <= n; num++){
            for(int j = num*num; j <= n; j++){
                dp[j] = min(dp[j], 1 + dp[j - num*num]);
                cout << j << ":" << dp[j] <<std::endl;
            }
        }
        return dp[n];
    }
    int numSquares1(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            int sq = (int)sqrt(i);
            if(sq*sq == i) {
                dp[i] = 1;
                cout << i << ":" << dp[i]<<std::endl;;
            }
            else{
                int sq = (int)sqrt(i);
                int j = 1;
                dp[i] = i;  // use '1'
                while(j <= sq){
                    dp[i] = min(dp[i], 1 + dp[i - j*j]);;
                    cout << i << ":" << dp[i]<<std::endl;;
                    j++;
                }
            }
        }
        return dp[n];
    }

    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[1] = 1;
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            int sq = (int)sqrt(i);
            if(sq*sq == i) {
                dp[i] = 1;
                cout << i << ":" << dp[i] <<std::endl;
            } else{
                for (int j=sq*sq;j<=i;j++) {
                    dp[j] = min(dp[j], 1 + dp[j-sq*sq]);
                    cout << j << ":" << dp[j]<<std::endl;;
                }
            }
        }
        return dp[n];
    }

};

DEFINE_CODE_TEST(279_perfectsquare)
{
    Solution obj;
    {
        obj.numSquares1(12);
        //VERIFY_CASE(PRINT_MATRIX(m),"1 0 1 0 0 0 1 0 1");
    }
}