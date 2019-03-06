//
// Created by Rui Zhou on 2/3/18.
//

/*
 * https://leetcode.com/problems/subsets/description/
 * Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

 hard-->
 find all subset, iterate ()->(),(1)->(),(1),(2),(1,2)
 */

#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace subset {
    class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res{{}};
            for (auto num : nums) {
                vector<vector<int>> tmp;
                for (auto &v : res) {
                    v.push_back(num);
                    tmp.push_back(v);
                }
                res.insert(res.end(), tmp.begin(), tmp.end());
            }
            return res;
        }

        // faster ===========================================
        vector<vector<int>> subsets1(vector<int>& nums) {
            vector<vector<int>> subs(1, vector<int>());
            for (int i = 0; i < nums.size(); i++) {
                int n = subs.size();
                for (int j = 0; j < n; j++) {
                    subs.push_back(subs[j]);
                    subs.back().push_back(nums[i]);
                }
            }
            return subs;
        }
        // TODO recursive
    };

    class Solution1 {
    public:
        vector<vector<int>> ret;
        void findsub(vector<int>& nums,vector<int> &comb, int start,int end) {
            if (start==end) {
                ret.emplace_back(comb);
                return;
            }
            comb.emplace_back(nums[start]);
            findsub(nums,comb,start+1,end);
            comb.pop_back();
            //or skip
            findsub(nums,comb,start+1,end);
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> comb;
            findsub(nums,comb,0,nums.size());
            return ret;
        }
    };


}

void printvec(vector<vector<int>> &&nums) {
    for_each(nums.begin(),nums.end(),[](auto v) {
        cout << "[";
        for (auto e : v) {
            cout << e << ",";
        }
        cout << "],";
    });
}


DEFINE_CODE_TEST(0078_subset)
{
    subset::Solution1 obj;
    {
        vector<int> nums{1,2,3};
        VERIFY_CASE(PRINT_VVEC(obj.subsets(nums)),"1 2 3 1 2 1 3 1 2 3 2 3");
    }

//    vector<int> nums;//{1,2,3};
//
//    for (int i=0; i <15; i++) {
//        nums.push_back(i);
//    }
//    TIMER(obj.subsets1(nums),1)
//    TIMER(obj.subsets(nums),1)
    //printvec(obj.subsets(nums));
}