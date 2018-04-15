//
// Created by rui zhou on 15/04/18.
//

/*
 *https://leetcode.com/problems/sort-list/description/
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* newHead = head;
        head = head->next;

        while (head) {
            merge(newHead, head);
            head = head->next;
        }
    }

    ListNode* merge(ListNode *a, ListNode *b) {
        ListNode* dummy = new ListNode(0);
        ListNode *head = dummy;
        while (a || b) {
            if (a && b) {
                if (a->val < b->val) {
                    head->next = a;a=a->next;head=head->next;head->next=nullptr;
                } else {
                    head->next = b;b=b->next;head=head->next;head->next=nullptr;
                }
            } else if (a) {
                head->next = a;break;
            } else if (b) {
                head->next = b;break;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }

};


DEFINE_CODE_TEST(148_sortlist)
{
    Solution obj;
    {
        ListNode *head = CREATE_LIST({4,7,8,1,3,9,12,102});
        VERIFY_CASE(PRINT_LIST(obj.sortList(head)),"1 3 4 7 8 9 10 12");
    }


}