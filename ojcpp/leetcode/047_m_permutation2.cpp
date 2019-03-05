//
// Created by rui.zhou on 3/5/2019.
//

/*
 * https://leetcode.com/problems/permutations-ii/
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;


//s实在难以判断退出条件
class Solution {
public:
    void dfs(int start, int end, vector<int> comb,vector<vector<int>> &ret) {
        if (start==end-1) {
            ret.emplace_back(comb);
            cout<<PRINT_VEC(std::move(comb))<<endl;
        }
        unordered_set<int> visited;
        for (int i=start;i<end;i++) {
            if (visited.count(comb[i])==0) {
                swap(comb[start],comb[i]);
                visited.emplace(comb[i]);
                dfs(start+1,end,comb, ret);
            }


        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(0,nums.size(),nums, ret);
        return ret;
    }
};



// 排列问题且唯一问题，可以用hashmap，从里面挑数字
DEFINE_CODE_TEST(047_permutation2)
{
    Solution obj;
    {
        vector<int> nums{2,2,1,1};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"3 3 0 3 3 3 3 0 3 0 3 3 0 3 3 3");
    }
    {
        vector<int> nums{3,3,0,3};

    }
    {
        vector<int> nums{1,1,2};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"1 1 2 1 2 1 2 1 1");
    }
    {
        vector<int> nums{1,1,1};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"1 1 1");
    }

    {
        vector<int> nums{1,1,1,2};
        VERIFY_CASE(PRINT_VVEC(obj.permuteUnique(nums)),"1 1 1 2 1 1 2 1 1 2 1 1 2 1 1 1");
    }




}