#ifndef ALGO_COMMON_H_
#define ALGO_COMMON_H_

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <deque>

namespace CODECH
{
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
        int len = list.size();
        if (idx < len)
        {
            int val = list[idx];
            if (val != 0)
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



}
#endif