//
// Created by Rui Zhou on 10/3/18.
//

/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
 */


#include <codech/codech_def.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int minpx = prices[0];
        int maxProfit = 0;
        for (auto &item:prices) {
            maxProfit = max(maxProfit, item-minpx);
            minpx = min(minpx, item);
        }
        return maxProfit;
    }
};

DEFINE_CODE_TEST(121_besttime_sellstock)
{
    Solution obj;
    vector<int> px{7,1,5,3,6,4};
    RUN_CASE(obj.maxProfit(px),5);

    vector<int> px2={7,6,4,3,1};
    RUN_CASE(obj.maxProfit(px2),0);
}