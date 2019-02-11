#ifndef ALGO_COMMON_H_
#define ALGO_COMMON_H_

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
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
    inline TreeNode* CREATE_TREENODE(int idx, const std::vector<int> &list)
    {
        size_t len = list.size();
        if (idx < len)
        {
            int val = list[idx];
            if (val != null)
            {
                TreeNode*node = new TreeNode(list[idx]);
                node->left = CREATE_TREENODE(idx * 2 + 1, list);
                node->right = CREATE_TREENODE(idx * 2 + 2, list);
                return node;
            }
            return nullptr;
        }
        else
        {
            return nullptr;
        }
    }

    //TreeNode *root = LCREATE_TREENODE({1,null,2,3,null,null,null});
    // 按每一层从左到右填满.
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

    inline TreeNode* LCREATE_TREENODE(const std::vector<int> &list)
    {
        TreeNode *root = new TreeNode(list[0]);
        std::deque<TreeNode*> toDo{root};

        for (int i=0; i < list.size(); i++) {
            TreeNode *parent = toDo.front();
            toDo.pop_front();
            int idx = i * 2 + 1;
            if (idx<list.size()) {
                int v1 = list[idx];
                if (v1 != null) {
                    parent->left = new TreeNode(v1);
                    toDo.push_back(parent->left);
                } else {
                    parent->left = nullptr;
                }
            }

            idx++;
            if (idx < list.size()) {
                int v2 = list[idx];
                if (v2 != null) {
                    parent->right = new TreeNode(v2);
                    toDo.push_back(parent->right);
                } else {
                    parent->right = nullptr;
                }
            }
        }
        return root;
    }
    // node data first
    inline void TREE_PREORDER(TreeNode*root)
    {
        if (root)
        {
            std::cout << root->data << " ";
            TREE_PREORDER(root->left);
            TREE_PREORDER(root->right);
        } else {
            std::cout << " null ";
        }
    }

    inline std::string TREE_BYLEVEL(TreeNode*root) {
        std::deque<TreeNode*> toDo{root};
        std::stringstream ss;
        while (!toDo.empty()) {
            TreeNode *node = toDo.front();
            toDo.pop_front();
            if (node) {
                ss << node->val <<",";
                toDo.push_back(node->left);
                toDo.push_back(node->right);
            } else {
                ss << "null,";
            }
        }
        return ss.str();
    }
    inline TreeNode* FIND_NODE(TreeNode *root, int val) {
        std::deque<TreeNode*> toDo{root};
        while (!toDo.empty()) {
            TreeNode *node = toDo.front();
            toDo.pop_front();
            if (node) {
                if (node->val == val)
                    return node;
                toDo.push_back(node->left);
                toDo.push_back(node->right);
            }
        }
        return nullptr;
    }

    // ==================================
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    inline ListNode * CREATE_LIST(int size)
    {
        ListNode *head = nullptr;
        ListNode *cur = nullptr;
        for (int i =1;i <= size; i++)
        {
            ListNode *pNode = new ListNode(i);
            if (head==nullptr)
            {
                head = pNode;cur = head;
            }
            else
            {
                cur->next = pNode; cur = pNode;
            }
        }
        return head;

    }
    inline ListNode * CREATE_LIST(std::vector<int> &&vec)
    {
        ListNode *head = nullptr;
        ListNode *cur = nullptr;
        size_t size = vec.size();
        for (size_t i =1;i <= size; i++)
        {
            ListNode *pNode = new ListNode(vec[i-1]);
            if (head==nullptr)
            {
                head = pNode;cur = head;
            }
            else
            {
                cur->next = pNode; cur = pNode;
            }
        }
        return head;

    }

    inline ListNode* FIND_LISTNODE(ListNode* head,int val)
    {
        std::unordered_set<ListNode*> sets;
        while (head)
        {
            auto iter = sets.find(head);
            if (iter==sets.end())
            {
                sets.insert(head);
                if (head->val == val)
                    return head;
                head = head->next;
            }
            else
            {
                // prevent a circle linked list
                return nullptr;
            }
        }
        return nullptr;
    }

    inline std::string PRINT_LIST(ListNode *head)
    {
        std::unordered_set<ListNode*> sets;
        std::stringstream ss;
        while (head)
        {
            auto iter = sets.find(head);
            if (iter==sets.end())
            {
                sets.insert(head);
                ss << head->val;
                head = head->next;
                if (head)
                    ss << " ";
            }
            else
            {
                // prevent a circle linked list
                break;
            }
        }
        return ss.str();
    }

    inline std::string PRINT_VEC(std::vector<int> &&vec) {
        std::stringstream ss;
        for (int i=0; i< vec.size(); i++) {
            ss << vec[i];
            if (i != vec.size()-1)
                ss << " ";
        }
        return ss.str();
    }

    inline std::string PRINT_VVEC(std::vector<std::vector<int>> &&m) {
        std::stringstream ss;
        for (auto &row : m){
            for (auto &v : row) {
                ss << v << " ";
            }
            ss << std::endl;
        }
        return ss.str();
    }

    inline std::string PRINT_STRVEC(std::vector<std::string>  &&m) {
        std::stringstream ss;
        for (auto &v : m) {
            ss << v << " ";
        }


        return ss.str();
    }

    inline std::string PRINT_MATRIX(std::vector<std::vector<int>> &m) {
            std::stringstream ss;
            for (auto &row : m){
                for (auto &v : row) {
                    ss << v << " ";
                }
            }
            return trim(ss.str());
    }
}
#endif