# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
#Output: 7 -> 0 -> 8
#Explanation: 342 + 465 = 807.

from doudoulib.linked_list import SinglyListNode as ListNode
from doudoulib.linked_list import SinglyLinkedList

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        m = 1
        sum = 0
        r = 0
        lst = []

        while l1 or l2 or r>0:
            val = r
            if l1:
                val+=l1.val
                l1 = l1.next
            if l2:
                val+=l2.val
                l2 = l2.next
            
            if val>=10:
                val = val-10
                r = 1
            else:
                r = 0
            lst.append(val)
            #m *= 10

        last_node = None
        first_node = None
        print(lst)
        for v in lst:
            node = ListNode(v)
            if not first_node:
                first_node = node
                last_node = node
            elif last_node:
                last_node.next = node
                last_node = node
        return first_node

def test1():
    l1 = ListNode(2)
    lst1 = SinglyLinkedList(l1)
    lst1.append(ListNode(4))
    lst1.append(ListNode(3))
    l2 = ListNode(5)
    lst2 = SinglyLinkedList(l2)
    lst2.append(ListNode(6))
    lst2.append(ListNode(4))

    print(str(lst1),str(lst2))
    obj = Solution()
    lst = obj.addTwoNumbers(l1, l2)

def test2():
    l1 = ListNode(0)
    l2 = ListNode(0)
    obj = Solution()
    print(obj.addTwoNumbers(l1, l2))


if __name__ == '__main__':
    test1()
