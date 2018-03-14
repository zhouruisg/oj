'''
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

8:22-8:49
hard---no idea
'''


class Solution:


    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[]]
        for num in sorted(nums):
            res += [item + [num] for item in res]
            print(res)
        return res

if __name__ == '__main__':
    obj = Solution()
    print(obj.subsets([3,2,4,1]))
