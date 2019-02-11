class Solution:
    def findMedianSortedArrays(self, nums1: 'List[int]', nums2: 'List[int]') -> 'float':
        nums1.extend(nums2)
        nums1.sort()
        return nums1[len(nums1)//2] if len(nums1) % 2 == 1 else (nums1[(len(nums1)//2)-1]+nums1[len(nums1)//2])/2
        
        
obj=Solution()
print(obj.findMedianSortedArrays([1,9,10],[]))