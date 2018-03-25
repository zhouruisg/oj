//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/missing-number/description/
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
 */

#include <codech/codech_def.h>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber0(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int exp = (n+1)*n/2;
        return exp-sum;
    }

    //
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;

        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }

        return result;
    }
};

DEFINE_CODE_TEST(268_missingnumber)
{
    Solution obj;
    vector<int> nums{3,0,1};
    VERIFY_CASE(obj.missingNumber(nums),2);

}