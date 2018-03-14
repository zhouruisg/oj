'''
https://leetcode.com/problems/linked-list-cycle/#/description
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Subscribe to see which companies asked this question.
'''

# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None


def create_list(lst):
    root = None
    last = None
    for el in lst:
        node = ListNode(el)
        if not root:
            root = node
            last = root
        else:
            last.next = node
            last = node
    return root


def print_list(root):
    while root:
        print root.val,
        root = root.next


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return False
        fast = head.next
        while head and fast and head != fast:
            head = head.next
            fast = fast.next
            if fast:
                fast = fast.next
            else:
                break
        return head == fast

'''
def hasCycle(self, head):
    try:
        slow = head
        fast = head.next
        while slow is not fast:
            slow = slow.next
            fast = fast.next.next
        return True
    except:
        return False
'''
if __name__ == '__main__':
    root = create_list([1, 3, 5, 7, 9])
    print_list(root)


