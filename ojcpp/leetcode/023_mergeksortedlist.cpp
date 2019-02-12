//
// Created by rui.zhou on 2/12/2019.
//

/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using vt = vector<ListNode*>::value_type ;
        auto comp = [](vt &a, vt &b){
            return a->val > b->val;
        };
        priority_queue<vt,vector<vt>,decltype(comp)> queue(comp);
        for (auto el:lists) {
            queue.push(el);
        }



    }
};