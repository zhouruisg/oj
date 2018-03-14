'''
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

Seen this question in a real interview before?  YesNo
https://leetcode.com/problems/merge-sorted-array/description/
similar to 021?
6:39-6:59
must cut the array length according to m/n
'''


class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        idx1 = 0
        idx2 = 0
        offset = 0
        # must cut the array length according to m/n
        if m != len(nums1):
            del nums1[-(len(nums1) - m):]
        while idx1 < m and idx2 < n:
            v1 = nums1[offset+idx1]
            v2 = nums2[idx2]
            if v2 <= v1:
                nums1.insert(offset+idx1, v2)
                offset += 1
                idx2 += 1
            else:
                idx1 += 1
        if idx1 == m:
            nums1.extend(nums2[idx2:n])


def test(a, b):
    obj = Solution()
    obj.merge(a, len(a), b, len(b))
    #print(a)
    return a

def test2(a,b):
    obj = Solution()
    obj.merge(a, 0, b, 1)
    return a

if __name__ == '__main__':
    #print(test([5, 6, 7, 8], [1, 2, 3])==[1,2,3,5,6,7,8])
    #print(test([1, 2, 3,9], [5, 6, 7, 8]) == [1, 2, 3, 5, 6, 7, 8,9])
    print(test([0], [1]) == [0,1])
    print(test2([0], [1]) == [1])