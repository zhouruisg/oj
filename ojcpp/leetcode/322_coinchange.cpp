//
// Created by rui.zhou on 4/10/2019.
//

/*
 * You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
 */

#include <codech/codech_def.h>
using namespace std;
namespace {
    // backtracking TLE
    class Solution0 {
    public:
        int coinChange(vector<int>& coins, int amount) {
            sort(coins.begin(),coins.end());
            int mincount=std::numeric_limits<int>::max();
            vector<int> comb;
            dfs(coins,amount,comb,mincount,0);
            return mincount==INT_MAX?-1:mincount;
        }

        void dfs(vector<int>&coins,int target,vector<int> &comb, int &mincount, int begin) {
            if (target==0) {
                mincount=min(int(comb.size()),mincount);
                return;
            }
            for (int i=begin;i<coins.size() && target>=coins[i];i++) {
                comb.emplace_back(coins[i]);
                dfs(coins,target-coins[i],comb,mincount,begin);
                comb.pop_back();
            }
        }
    };
    // DP
    //dp(i-1),dp(i)
    class Solution {
    public:
        int coinChange(vector<int> &coins, int amount) {
            vector<int64_t> dp(amount+1,INT_MAX);
            dp[0]=0;
            for (auto coin:coins) {
                for (int i=coin;i<=amount;i++) {
                    dp[i] = min(dp[i],dp[i-coin]+1);
                }
            }
            return dp[amount]==INT_MAX?-1:dp[amount];
        }
    };
}

DEFINE_CODE_TEST(322_coinchange)
{
    Solution obj;
    {
        vector<int> nums{2};
        VERIFY_CASE(obj.coinChange(nums, 3),-1);
    }
    {
        vector<int> nums{1,2,5};
        VERIFY_CASE(obj.coinChange(nums, 11),3);
        VERIFY_CASE(obj.coinChange(nums, 100),20);
    }
}

