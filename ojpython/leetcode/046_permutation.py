'''
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
https://leetcode.com/problems/permutations/description/
'''

from copy import deepcopy
class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        self.recursive(nums,0,result)
        return result

    def recursive(self, nums, start, result):
        if start == len(nums)-1:
            result.append(nums)
        else:
            for cur in range(start, len(nums)):
                tmplst = deepcopy(nums)  # must create a copy
                tmplst[cur], tmplst[start] = tmplst[start], tmplst[cur]
                self.recursive(tmplst, start+1, result)
        pass



if __name__ == '__main__':
    obj = Solution()
    print(obj.permute([1,2,3]))
    print(obj.permute([1, 2, 3, 4]))
