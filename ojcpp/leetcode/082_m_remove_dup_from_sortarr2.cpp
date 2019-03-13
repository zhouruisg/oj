//
// Created by rui.zhou on 3/13/2019.
//

/* linkedlist
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
using namespace std;
using namespace CODECH;

 namespace lc082 {
     class Solution {
     public:
         ListNode* deleteDuplicates(ListNode* head) {
            ListNode dummy(0);
            ListNode*prev=&dummy;


         }
     };
 }

 DEFINE_CODE_TEST(082_remove_dup_sortlist)
{

}
