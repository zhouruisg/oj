'''
https://leetcode.com/problems/two-sum/description/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        maps = {}
        ret = []
        for idx, val in enumerate(nums):
            key = target - val;
            if key in maps:               
                ret.append(maps[key])
                ret.append(idx)                
                break
            else:
                maps[val] = idx
        return ret

    
obj = Solution()
print obj.twoSum([2,7,11,15],9)