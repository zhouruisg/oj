//
// Created by rui zhou on 27/03/18.
//

/*
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 * You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].


 */

#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

    }
};


DEFINE_CODE_TEST(315_countsmallernumber_afterself)
{
    Solution obj;
    {
        vector<int>nums{5,2,6,1};
        obj.countSmaller(nums);
    }
}