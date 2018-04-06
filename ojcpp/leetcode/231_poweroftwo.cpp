//
// Created by Rui Zhou on 30/3/18.
//

/*
 * https://leetcode.com/problems/power-of-two/description/
 *
 */

#include <codech/codech_def.h>

using namespace std;

namespace yt {
    int Count(const vector<int>& nums)
    {
        int count = 0;
        for (int i = 0;i < nums.size();i++) {
            int sum = nums[i];
            if (sum>=7 && (sum  % 7 ==0))
                count++;
            for (int j = i+1;j<nums.size();j++) {
                sum += nums[j];
                if (sum >= 7 && (sum % 7 ==0)) {
                    count++;
                }
            }
        }
        return count;
    }
}

