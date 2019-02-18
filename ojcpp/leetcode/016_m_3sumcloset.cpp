//
// Created by rui zhou on 18/02/19.
//

/*
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

    }
};

DEFINE_CODE_TEST(016_3sumcloset)
{
    Solution obj;
    {
        vector<int> nums{-1, 2, 1, -4};
        VERIFY_CASE(obj.threeSumClosest(nums,1)),0);
    }
    {
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        VERIFY_CASE(PRINT_VVEC(obj.threeSum(nums)),"-1 -1 2 -1 0 1 ");
    }


}


