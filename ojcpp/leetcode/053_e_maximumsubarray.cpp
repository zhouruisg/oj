//
// Created by Rui Zhou on 29/3/18.
//

/*
 * https://leetcode.com/problems/maximum-subarray/description/
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


 */
#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0],cursum = nums[0];
        for (int i=1;i<nums.size();i++) {
            cursum = max(nums[i],cursum+nums[i]);
            maxsum = max(cursum, maxsum);
        }
        return maxsum;
    }

    // divide and conquer
//    int maxSubArray(vector<int>& nums) {
//        int maxsum = nums[0],cursum = nums[0];
//        for (int i=1;i<nums.size();i++) {
//            cursum = max(nums[i],cursum+nums[i]);
//            maxsum = max(cursum, maxsum);
//        }
//        return maxsum;
//    }
};

DEFINE_CODE_TEST(053_maximum_subarray)
{
    Solution obj;
    {
        vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
        VERIFY_CASE(obj.maxSubArray(nums),6);
    }
}