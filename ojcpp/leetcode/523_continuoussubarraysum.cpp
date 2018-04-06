//
// Created by Rui Zhou on 30/3/18.
//

/*
 * Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

 */


// hello

// 10级台阶， 有一个人，需要从台阶底部，走上顶部。
// 每次可以走1级，也可以走2级，请问他走上10级台阶有多少种不同的走法？


// count, 输入 int 类型数组， 假设每个数都是正整数。
// nums[i] <= 1000, size(nums) <= 10000
// return int, 表示 多少个子串，序列和，是 7的倍数。
// 3, 6, 7, 1, 2, 7
// [7], [6, 7, 1], [7], return 3, 连续的

#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
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
};


DEFINE_CODE_TEST(523_continuous_subarray)
{
//    {
//        vector<int> nums{3, 6, 7, 1, 2, 7};
//        VERIFY_CASE(yt::Count(nums),3);
//    }
//
//    {
//        vector<int> nums{7};
//        VERIFY_CASE(yt::Count(nums),1);
//    }
//    {
//        vector<int> nums{1,2,4};
//        VERIFY_CASE(yt::Count(nums),1);
//    }
//
//    {
//        vector<int> nums{0,0,0};
//        VERIFY_CASE(yt::Count(nums),0);
//    }
//
//    {
//        vector<int> nums{7,7,7};
//        VERIFY_CASE(yt::Count(nums),6);
//    }
//
//    {
//        vector<int> nums{1,1,1,1,1,1,1};
//        VERIFY_CASE(yt::Count(nums),1);
//    }



}