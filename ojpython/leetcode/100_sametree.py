'''
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.


Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
'''

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        from collections import deque
        def iterate_tree(root):
            sp = deque([root])
            lp = []
            while len(sp):
                node = sp.popleft()
                if not node:
                    lp.append(None)
                    continue
                lp.append(node.val)
                sp.append(node.left)
                sp.append(node.right)
            return lp
        lp = iterate_tree(p)
        lq = iterate_tree(q)
        return lp==lq



if __name__ == '__main__':
    obj = Solution()

