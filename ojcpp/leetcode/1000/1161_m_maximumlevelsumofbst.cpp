//
// Created by rui.zhou on 9/30/2019.
//

/*
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.



Example 1:



Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.


Note:

The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5

 NOT A BIG DEAL
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    class Solution {
    public:
        int maxLevelSum(TreeNode* root) {
            deque<TreeNode*> todo{root};
            int maxSum = INT_MIN;
            int ans = 0;
            int levelIdx = 1;
            while (!todo.empty()) {
                vector<TreeNode*> level;
                int sum = 0;
                while (!todo.empty()) {
                    auto node=todo.front();
                    todo.pop_front();
                    if (node->left)
                        level.emplace_back(node->left);
                    if (node->right)
                        level.emplace_back(node->right);
                    sum+=node->val;
                }
                if (sum>maxSum) {
                    maxSum=sum;
                    ans = levelIdx;
                }
                for (auto &node:level) {
                    todo.emplace_back(node);
                }
                levelIdx++;
            }
            return ans;
        }
    };
}