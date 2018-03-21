//
// Created by Rui Zhou on 14/3/18.
//

/*
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 * Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

 medium?
 like quantcast interview
 */


#include <codech/codech_def.h>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<int> queue;

        vector<int> ret;

        for (auto &iter : nums) {

        }
    }
};


DEFINE_CODE_TEST(347_topk_frequent_element)
{

}