//
// Created by rui zhou on 28/02/19.
//

/*
 * Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *cur=head,*tail=nullptr;
        ListNode revdummy(0);
        ListNode newhead(0);
        for (int i=1;i<=n;i++) {
            ListNode*next=cur->next;
            if (i>=m && i<=n) {
                ListNode *tmp = revdummy.next;
                revdummy.next=cur;
                cur->next=tmp;
                if (i==n) {
                    if (tail) {
                        tail->next=cur;
                    }
                }
            } else {
                tail=cur;
            }
            cur=next;
        }

    }
};

