'''
https://leetcode.com/problems/search-insert-position/description/
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
12:20-
'''


class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        start = 0
        end = len(nums) - 1
        mid = 0
        while start <= end:
            mid = int((end - start) / 2) + start
            #print(nums[mid],start,mid,end)
            if target < nums[mid]:
                end = mid-1
            elif target > nums[mid]:
                start = mid+1
            else:
                return mid

        if target < nums[mid]:
            return mid
        elif target > nums[mid]:
            return mid + 1
        else:
            return mid



if __name__ == '__main__':
    obj = Solution()
    print(obj.searchInsert([1,3,5,7],5) == 2)
    print(obj.searchInsert([1, 3, 5, 7], 4)==2)
    print(obj.searchInsert([1, 3, 5, 6], 2) == 1)