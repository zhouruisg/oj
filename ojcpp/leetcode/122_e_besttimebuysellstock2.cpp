/*
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
->
if see lower price sell stock on previous day
 */

#include <codech/codech_def.h>
#include <vector>

using namespace std;

class Solution {
public:
    // not a beautiful code
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int profit = 0;
        int prev = prices[0];
        int buy = -1;

        for (auto &p:prices)
        {
            if (p < prev)
            {
                if (buy>=0)
                {
                    profit += prev - buy;
                    buy = -1;
                }   
            } else {
               if (buy==-1)
                   buy = prev;
            }
            prev = p;
        }
        if (buy>=0)
        {
            profit += prev - buy;
            buy = -1;
        }
        return profit;
    }
};


DEFINE_CODE_TEST(122_besttime_tobuysell_stock2)
{
    Solution obj;
    {
        vector<int> px{ 7,1,5,3,6,4 };
        VERIFY_CASE(obj.maxProfit(px), 7);
    }
    {
        vector<int> px{ 2,1,2,0,1};
        VERIFY_CASE(obj.maxProfit(px), 2);
    }
    

}