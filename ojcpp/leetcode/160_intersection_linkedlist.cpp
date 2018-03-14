//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 * Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

 */
#include <codech/codech_def.h>
#include <unordered_set>
#include <codech/algo_common.h>

using namespace CODECH;
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes;
        while (headA) {
            nodes.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            auto &&iter = nodes.find(headB);
            if (iter!=nodes.end()) {
                return headB;
            }
            headB = headB->next;
        }

        return nullptr;
    }
};


DEFINE_CODE_TEST(160_intersection_linkedlist)
{


}
