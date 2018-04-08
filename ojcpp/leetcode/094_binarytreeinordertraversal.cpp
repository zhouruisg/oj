//
// Created by Rui Zhou on 5/4/18.
//

/*
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 * Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;
using namespace std;

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
    vector<int> inorderTraversal(TreeNode* root) {
        return {};
    }
};

DEFINE_CODE_TEST(094_binarytree_inorder_traversal)
{
    TreeNode *root = LCREATE_TREENODE({1,null,2,3,null});

}
