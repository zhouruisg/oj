//
// Created by rui zhou on 2019-09-03.
//

/* https://leetcode.com/problems/daily-temperatures/
 * Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 */

#include <codech/codech_def.h>

using namespace std;

namespace {
    class Solution0 {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            vector<int> ret;
            for (size_t i=0;i<T.size();i++) {
                bool found = false;
                for (size_t j=i+1;j<T.size();j++) {
                    if (T[j]>T[i]) {
                        ret.emplace_back(j-i);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ret.emplace_back(0);
                }
            }
            return ret;
        }
    };

    class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            vector<int> ret;
            for (size_t i=0;i<T.size();i++) {
                bool found = false;
                for (size_t j=i+1;j<T.size();j++) {
                    if (T[j]>T[i]) {
                        ret.emplace_back(j-i);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ret.emplace_back(0);
                }
            }
            return ret;
        }
    };
}

DEFINE_CODE_TEST(739_daily_temperature)
{
    Solution obj;
    {



    }
}