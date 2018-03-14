'''
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

https://leetcode.com/problems/maximum-subarray/description/
11:46 -
'''

# return the array
class Solution0:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lastsum = 0
        maxsum = nums[0]
        maxstart = 0
        maxend = 0
        laststart = 0
        for idx in range(0, len(nums)):
            lastsum += nums[idx]
            if lastsum < 0:
                lastsum = 0
                laststart = idx + 1
                if nums[idx] > maxsum:
                    maxsum = nums[idx]
                    maxstart = idx
                    maxend = idx
            elif lastsum > maxsum:
                maxsum = lastsum
                maxstart = laststart
                maxend = idx

        return nums[maxstart:maxend + 1]


# return sum
class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cursum = maxsum = nums[0]

        for num in nums[1:]:
            cursum = max(num, cursum + num)
            maxsum = max(maxsum, cursum)

        return maxsum

def test(input):
    obj=Solution0()
    return ','.join([str(x) for x in obj.maxSubArray(input)])


def test1(input):
    obj = Solution()
    return obj.maxSubArray(input)




if __name__ == '__main__':
    '''
    print(test([-2,1,-3,4,-1,2,1,-5,4])=='4,-1,2,1')
    print(test([-2,1,-3,4,-1,-2,-1,-5,4])=='4')
    print(test([-2,-5])=='-2')
    print(test([-5, -2]) == '-2')
    print(test([-5, -2, 4]) == '4')
    print(test([4]) == '4')
    '''
    print(test1([-2,1,-3,4,-1,2,1,-5,4])==6)
