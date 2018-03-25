//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/majority-element/description/
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
 best answer is hard
 */

#include <codech/codech_def.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int majorityElement0(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // N*LogN
        int x = nums[nums.size()/2];
        return x;
    }

    // still slow
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;  // O(N)
        for (auto &&iter : nums) {
            if (++counts[iter] > nums.size()/2) {
                return iter;
            }
        }
        return 0;
    }
    //Boyer-Moore Majority Vote Algorithm
    //http://www.cs.utexas.edu/~moore/best-ideas/mjrty/

};


DEFINE_CODE_TEST(169_majority_elements)
{
    vector<int> nums{3,3,2,3,1,3,2,3};
    Solution obj;
    VERIFY_CASE(obj.majorityElement(nums),3);
}

