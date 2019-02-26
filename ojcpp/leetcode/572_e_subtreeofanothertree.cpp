//
// Created by rui.zhou on 2/26/2019.
//

/*
 * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//使用recursive的方法，感觉比较耗时?
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s==nullptr && t)
            return false;
        else if (!s && !t)
            return true;

        bool ret = helper(s,t);
        if (!ret)
            ret = isSubtree(s->left,t);
        if (!ret)
            ret = isSubtree(s->right,t);
        return ret;
    }

    bool helper(TreeNode* s, TreeNode* t) {
        if (s && t) {
            return
            ((s->val == t->val) &&
            (helper(s->left,t->left)) &&
            (helper(s->right,t->right)));
        } else if (!s && !t) {
            return true;
        } else {
            return false;
        }
    }
};

DEFINE_CODE_TEST(572_subtree)
{
    Solution obj;
    {
        vector<int> nums1{1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,null,1,2};
        TreeNode* root1 = LCREATE_TREENODE(nums1);
        vector<int> nums2{1,null,1,null,1,null,1,null,1,null,1,2};
        TreeNode* root2 = LCREATE_TREENODE(nums2);
        VERIFY_CASE(obj.isSubtree(root1,root2), true);
    }
    {
        vector<int> nums1{3,4,5,1,2,null,null};
        TreeNode* root1 = LCREATE_TREENODE(nums1);
        vector<int> nums2{4,1,2};
        TreeNode* root2 = LCREATE_TREENODE(nums2);
        VERIFY_CASE(obj.isSubtree(root1,root2), true);
    }
    {
        vector<int> nums1{3,4,5,1,2,null,null,null,null,0};
        TreeNode* root1 = LCREATE_TREENODE(nums1);
        vector<int> nums2{4,1,2};
        TreeNode* root2 = LCREATE_TREENODE(nums2);
        VERIFY_CASE(obj.isSubtree(root1,root2), false);
    }

}

