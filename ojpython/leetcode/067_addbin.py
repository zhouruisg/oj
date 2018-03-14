'''
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
https://leetcode.com/problems/add-binary/description/
6:15 - 6:27
'''


class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        maxlen = max(len(a), len(b))
        idx = 1
        r = 0
        sum = []
        while idx <= maxlen:
            v = (int(a[-idx]) if idx<=len(a) else 0) + (int(b[-idx]) if idx<=len(b) else 0) + r
            r = 1 if v>=2 else 0
            v = v if v<2 else v-2
            sum.append(str(v))
            idx += 1
        if r>0:
            sum.append(str(r))

        return ''.join(sum[::-1])


# more simple
class Solution1:
    # @param {string} a
    # @param {string} b
    # @return {string}
    def addBinary(self, a, b):
        return bin(int(a,2) + int(b,2))[2:]

if __name__ == '__main__':
    obj = Solution()
    print(obj.addBinary("11","1")=="100")
    print(obj.addBinary("11", "11") == "110")

