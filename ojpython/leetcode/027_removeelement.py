'''
Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.
7:45

'''


class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        cur = 0
        end = len(nums)-1
        while cur<=end:
            if nums[cur] == val:
                nums[end], nums[cur] = nums[cur], nums[end]
                end -= 1
            else:
                cur += 1

        return end + 1

if __name__ == '__main__':
    obj = Solution()
    print(obj.removeElement([3,2,2,3], 3)==2)
    print(obj.removeElement([1], 1) == 0)