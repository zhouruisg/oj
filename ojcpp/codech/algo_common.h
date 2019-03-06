#ifndef ALGO_COMMON_H_
#define ALGO_COMMON_H_

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <deque>
#include <climits>
#include "codech_util.h"

namespace CODECH
{
    //const long null = LONG_MAX;
    const int null = INT_MIN;
    //const double null = std::numeric_limits<double>::infinity();

    struct TreeNode {        
        int data;
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : data(x), val(x), left(NULL), right(NULL) {}
    };

    // create tree per layer
    TreeNode* CREATE_TREENODE(int idx, const std::vector<int> &list);

    //TreeNode *root = LCREATE_TREENODE({1,null,2,3,null,null,null});
    // ��ÿһ�����������.
//    inline TreeNode* LCREATE_TREENODE(const std::vector<int> &list)
//    {
//        TreeNode *root = new TreeNode(list[0]);
//        std::deque<TreeNode*> toDo{root};
//
//        for (int i=1; i < list.size()-1; i+=2) {
//            TreeNode *parent = toDo.front();
//            toDo.pop_front();
//            if (i<list.size()) {
//                int v1 = list[i];
//                if (v1 != null) {
//                    parent->left = new TreeNode(v1);
//                    toDo.push_back(parent->left);
//                } else {
//                    parent->left = nullptr;
//                }
//            }
//            if ((i+1) < list.size()) {
//                int v2 = list[i + 1];
//                if (v2 != null) {
//                    parent->right = new TreeNode(v2);
//                    toDo.push_back(parent->right);
//                } else {
//                    parent->right = nullptr;
//                }
//            }
//        }
//        return root;
//    }

    TreeNode* LCREATE_TREENODE(const std::vector<int> &list);

    // node data first
    std::string TREE_PREORDER(TreeNode*root);

    std::string TREE_BYLEVEL(TreeNode*root);

    TreeNode* FIND_NODE(TreeNode *root, int val);

    // ==================================
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode * CREATE_LIST(int size);

    ListNode * CREATE_LIST(std::vector<int> &&vec);

    ListNode* FIND_LISTNODE(ListNode* head,int val);

    std::string PRINT_LIST(ListNode *head);

    std::string PRINT_VEC(std::vector<int> &&vec);

    std::string PRINT_VVEC(std::vector<std::vector<int>> &&m);

    std::string PRINT_STRVEC(std::vector<std::string>  &&m);

    std::string PRINT_MATRIX(std::vector<std::vector<int>> &m);

    // graph ===========================================================
    struct UndirectedGraphNode {
        int val;
        std::vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : val(x) {};
    };

    UndirectedGraphNode* CREATE_GRAPH(std::vector<std::vector<int>> &adjList);
    std::string GRAPH_BFS(UndirectedGraphNode *node);
}
#endif