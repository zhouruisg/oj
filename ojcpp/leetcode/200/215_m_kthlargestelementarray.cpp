//
// Created by Rui Zhou on 16/3/18.
//

/*
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include <codech/codech_def.h>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue;
        for (auto &n: nums) {
            queue.emplace(n);
            if (queue.size() > k ) {
                queue.pop();
            }
        }
        return queue.top();
    }
};


DEFINE_CODE_TEST(215_kth_largestelement_array)
{
    Solution obj;
    {
        vector<int> nums{3,2,1,5,6,4};
        VERIFY_CASE(obj.findKthLargest(nums, 2), 5);
    }
}

