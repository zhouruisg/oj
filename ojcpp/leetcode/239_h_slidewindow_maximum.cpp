//
// Created by rui.zhou on 3/14/2019.
//

/* amazon
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
 找出滑动窗口的最大值,用priority_queue可以解决
 如何做到O(N)?

 */
#include <codech/codech_def.h>
using namespace std;

namespace lc239 {
    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ret;
            int themax=INT_MIN;
            int cur=0;
            while (cur<k) {
                themax=max(themax,nums[cur]);
                cur++;
            }
            for (int i=cur;i<nums.size();i++) {

            }
        }
    };
}