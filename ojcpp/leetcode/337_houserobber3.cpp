//
// Created by rui.zhou on 4/12/2019.
//

/*
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace {
    class Solution {
    public:
        int maxVal = INT_MIN;
        int rob(TreeNode* root) {
            int amount=0;
            dfs(root, amount, false);
            return maxVal;
        }
        void dfs(TreeNode *node, int &amount, bool skip) {
            if (!node)
                return;
            if (!skip) {
                amount+=node->val;
                dfs(node->left,amount,true);
                dfs(node->right,amount,true);
                maxVal=max(amount,maxVal);
                //amount-=node->val;
            }
            dfs(node->left,amount,false);
            dfs(node->right,amount,false);
            maxVal=max(amount,maxVal);
        }
    };
}


DEFINE_CODE_TEST(337_rob_house3)
{
    Solution obj;
    TreeNode *root=LCREATE_TREENODE({3,4,5,1,3,null,1,null,null,null,null,null,null});
    VERIFY_CASE(obj.rob(root),7);
}