'''
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
'''

from doudoulib.linked_list import SinglyLinkedList as LinkedList
from doudoulib.linked_list import SinglyListNode as ListNode

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        cur = head

        while l1 or l2:
            if l1 and l2:
                if l1.val < l2.val:
                    cur.next = l1
                    l1 = l1.next
                else:
                    cur.next = l2
                    l2 = l2.next
                cur = cur.next
                continue

            if l1:
                cur.next = l1
                cur = l1
                l1 = l1.next
                continue
            if l2:
                cur.next = l2
                cur = l2
                l2 = l2.next
                continue

        return head.next


'''
while l1 and l2 loop
cur = l1 or l2
'''