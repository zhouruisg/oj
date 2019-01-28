//
// Created by Rui Zhou on 16/3/18.
//

/*
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 * find the duplicate one.

 Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3

Note:
You must not modify the array (assume the array is read only).  no sort
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

 medium
 关键是让数组形成一个闭环，1 3 4 2 2如何形成cycle？
 如果仅以数值来连接，那需要一个hashmap来记住每一个数字的所在node,例如1 2 3 4 2,最后一个2的时候如何重新指向前面出现的2
 另一种思路:
 以每个位置的数值作为下一个node的index,例如1 2 3 4 2 那么就会变成[N0/1]->[N1/2]->[N2/3]->[N3/4]->[N4/2]->[N2/3],
 从而在3/4/2之间形成一个cycle.通过龟兔快慢指针可以在这个cycle上的某一点相遇
 接下来需要再来一次循环，确定原数组何处可以进入这个cycle.

 */

#include <codech/codech_def.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        // find the entrance to the cycle
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};


DEFINE_CODE_TEST(287_m_findduplicatenumber)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,4,2};
        VERIFY_CASE(obj.findDuplicate(nums),2);
    }
    {
        vector<int> nums{1,2,3,4,4,5};
        VERIFY_CASE(obj.findDuplicate(nums),4);
    }
    {
        vector<int> nums{6,1,2,3,4,4,5};
        VERIFY_CASE(obj.findDuplicate(nums),4);
    }
    {
        vector<int> nums{6,1,4,3,4,4,5};
        VERIFY_CASE(obj.findDuplicate(nums),4);
    }

}
