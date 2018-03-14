'''
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

https://leetcode.com/problems/multiply-strings/description/
11:47-11:53
'''

import functools
class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        lst = []
        for id1, a in enumerate(num2[::-1]):
            sum = 0
            a1 = int(a)
            r = 0
            for id2, b in enumerate(num1[::-1]):
                b1 = int(b)
                sum += ((a1*b1) % 10 + r)* (10**id2)
                r = int(a1*b1/10)

            #print(sum,r)
            sum += r * (10 ** len(num1))
            #print(a1,'*',num1,'=',sum*(10**id1))
            lst.append(sum*(10**id1))

        return str(functools.reduce(lambda a, b: a + b, lst))
        #print(sum(lst))


if __name__ == '__main__':
    obj = Solution()
    print(obj.multiply("100","70"))
    print(obj.multiply("123", "78"))
