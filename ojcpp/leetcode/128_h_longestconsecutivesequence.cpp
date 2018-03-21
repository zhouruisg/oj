//
// Created by Rui Zhou on 15/3/18.
//

/*
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

hard->
 I only know O(N*LogN)
-> use ordered_map to remember each num's consecutive length
 5:32
 */

#include <codech/codech_def.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    //
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> record(num.begin(),num.end());
        int res = 1;
        for(int n : num){
            if(record.find(n)==record.end()) continue;
            record.erase(n);  //erase the item to avoid visit again.
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }


    int longestConsecutive1(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxLength = 0;
        for (auto &n : nums) {
            if (map.find(n)!=map.end())
                continue;
            int left = 0, right = 0;
            auto ir = map.find(n+1);
            if (ir!=map.end()) {
                right = ir->second;
            }

            auto il = map.find(n-1);
            if (il!=map.end()) {
                left = il->second;
            }
            int sum = left + right + 1;
            map[n] = sum;
            map[n+right] = sum;  // important to spread the result to the rightest item
            map[n-left] = sum;

            maxLength = max(maxLength, sum);
        }
        return maxLength;
    }

};

DEFINE_CODE_TEST(128_longest_consecutive_sequence)
{

    Solution obj;
    {
        vector<int> nums {100,4,200,1,3,2};
        VERIFY_CASE(obj.longestConsecutive1(nums),4);
    }
    {
        vector<int> nums {100,4,200,1,3,2,5};
        VERIFY_CASE(obj.longestConsecutive1(nums),5);
    }
    {
        vector<int> nums {100,4,200,1,3,2,101,102,102,103,104};
        VERIFY_CASE(obj.longestConsecutive1(nums),5);
    }
    {
        vector<int> nums {1,2,0,1};
        VERIFY_CASE(obj.longestConsecutive1(nums),3);
    }

}


