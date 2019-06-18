//
// Created by rui.zhou on 6/18/2019.
//

/*
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
 */
#include <codech/codech_def.h>
using namespace std;

namespace {

    class Solution {
    public:
        int findUnsortedSubarray(vector<int> &nums) {
            if (nums.empty()) return 0;
            int start = INT_MIN, end = -1;
            int maxNum = nums[0];
            for (int i=1;i<nums.size();i++) {
                if (nums[i]<=maxNum) {
                    if (start==INT_MIN)
                        start = i-1;
                    //start = (start==INT_MIN?i-1:start);
                    end = i;
                } else {
                    maxNum = nums[i];
                }
            }
            if (start==INT_MIN) return 0;
            return end-start+1;
        }
    };
}

DEFINE_CODE_TEST(581_shortest_unsorted_array)
{
    Solution obj;
    {
        vector<int> nums{2,3,3,2,4};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),3);
    }
    {
        vector<int> nums{1,2,3,3,3};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),0);
    }
    {
        vector<int> nums{9,8,7,6,5,4,3,2,1};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),9);
    }
    {
        vector<int> nums{2,6,4,8,10,9,15};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),5);
    }
    {
        vector<int> nums{2,6,4,8,10,15};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),2);
    }
    {
        vector<int> nums{2,4,6,8,10,15};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),0);
    }
    {
        vector<int> nums{};
        VERIFY_CASE(obj.findUnsortedSubarray(nums),0);
    }

}