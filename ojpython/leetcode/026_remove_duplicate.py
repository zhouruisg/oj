'''
https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.


'''

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        # indicate tail
        new_tail = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[new_tail]:
                new_tail += 1
                nums[newTail] = nums[i]
        return new_tail + 1


if __name__ == '__main__':
    print Solution().removeDuplicates(sorted([1, 2, 3, 2]))
