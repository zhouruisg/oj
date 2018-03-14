//
// Created by Rui Zhou on 2/3/18.
//
/*
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 * Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 1->2->3  ==> 2->1->3
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* a = head;
        ListNode* b = head->next;

        ListNode* next = b?b->next:nullptr;
        if (b) {
            b->next = a;
            if (next) {
                a->next = swapPairs(next);
            } else {
                a->next = nullptr;
            }
            return b;
        } else {
            return a;
        }
    }
};


DEFINE_CODE_TEST(swap_in_pair)
{
    Solution obj;
    ListNode *head = CREATE_LIST({1,2,3,4});
    ListNode *newHead = obj.swapPairs(head);
    PRINT_LIST(newHead);
}