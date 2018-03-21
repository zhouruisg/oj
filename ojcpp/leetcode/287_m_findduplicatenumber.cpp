//
// Created by Rui Zhou on 16/3/18.
//

/*
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).  sort?
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

 medium
 1,2,3,4,4,5
 1,2,3,4,5 xor -> 4

 1,2,4,4,4,5
 1,2,3,4,  5 xor->3

 1,3,5,5,5,5
 1,2,3,4,  5

 4,6,5,5,5,5 ->
 */

#include <codech/codech_def.h>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

    }
};


DEFINE_CODE_TEST(287_m_findduplicatenumber)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,4,4,5};
        VERIFY_CASE(obj.findDuplicate(nums),4);
    }
    {
        vector<int> nums{6,1,2,3,4,4,5};
        VERIFY_CASE(obj.findDuplicate(nums),4);
    }

}
