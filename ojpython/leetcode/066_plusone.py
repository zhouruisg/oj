class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        h = 1
        for idx, el in reversed(list(enumerate(digits))):
            if h!=0:
                r = (el+h) % 10
                h = (el+1) / 10
                #el = r
                digits[idx] = r
        if h!=0:
            digits.insert(0, h)
        return digits

if __name__ == '__main__':
    print Solution().plusOne([1, 2, 3])
    print Solution().plusOne([1, 2, 9])
    print Solution().plusOne([9])
    print Solution().plusOne([0])
