'''
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

https://leetcode.com/problems/3sum/description/
11:20

transfer to twosum problem
'''

# time exceed ---
from itertools import *
class Solution0:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        l = combinations(nums, 3)
        out = []
        for item in l:
            if sum(item) == 0:
                out.add(tuple(sorted(item)))
        #print(list(out))
        return list(out)


def test(nums):
    obj = Solution0()
    # print(obj.threeSum([-1, 0, 1, 2, -1, -4])==[(-1, -1, 2), (-1, 0, 1)])
    # print(obj.threeSum([4, -1, 0, 1, 2, -1, -4])==[(-1, -1, 2), (-1, 0, 1), (-4, 0, 4)])
    return obj.threeSum(
        [7, -13, -1, 1, -6, 14, 10, -2, 1, 9, 11, -10, 8, -10, 14, 13, -1, 4, -6, -3, -5, 3, 3, 12, -5, 11, 5, -6, -2,
         0, -6, 12, 3, 0, -2, 12, -1, -7, -5, 8, 10, 13, 13, 3, 10, 12, -7, -6, -7, -5, -1, 3, 5, -13, -8, -15, 13, 13,
         -14, -12, -2, -5, -15, 8, 11, -1, 6, -13, -1, 8, 10, -14, -1, 0, -4, -6, -3, 5, -4, -2, 7, 10, 8, -3, 12, -14,
         -10, 3, 14, -9, -2, -11, -6, -9, 13, 12, -3, 4, 14, 3, -11, 2, 5, -5, -13, -14, -3, -8])

    #return obj.threeSum(nums)


class Solution:
    def twoSum(self, nums, target):
        maps = {}
        ret = set()
        if len(nums) < 2:
            return ret

        for idx, val in enumerate(nums):
            key = target - val
            if key in maps:
                ret.add(tuple(sorted([-target, key, val])))
            else:
                maps[val] = idx
        return ret

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        arr =sorted(nums)
        ret = set()
        lastval = None
        for idx, val in enumerate(arr):
            if idx == 0:
                lastval = val
            elif val == lastval:
                continue

            target = 0 - val
            twosum = self.twoSum(arr[idx+1:], target)
            if twosum:
                for tp in twosum:
                    ret.add(tp)
            lastval = val
        return list(ret)


def test2():
    obj = Solution()
    print(obj.threeSum([-1, 0, 1, 2, -1, -4]))  #==[(-1, -1, 2), (-1, 0, 1)])
    print(obj.threeSum([4, -1, 0, 1, 2, -1, -4])) ##==[(-1, -1, 2), (-1, 0, 1), (-4, 0, 4)])

    pass

if __name__ =='__main__':
    test2()
