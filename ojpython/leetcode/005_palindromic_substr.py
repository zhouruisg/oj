"""
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
palindromic means origin = reverse

create a state 2D array/map


DP -
"""

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        # state = {}
        sz = len(s)
        f = [([False] * sz) for i in range(sz)]

        start = 0
        maxlen = 1
        for i, c in enumerate(s):
            f[i][i] = True
            for j in range(0, i):
                f[j][i] = (s[j] == s[i] and (i-j < 2 or f[j+1][i-1] == True))
                if f[j][i] and maxlen < (i-j+1):
                    maxlen = i-j+1
                    start = j
                    print(start, maxlen, 'is palindromic', j,i)

        #print(start,maxlen)
        return s[start:start+maxlen]




if __name__ == '__main__':
    obj = Solution()
    print(obj.longestPalindrome("babad")=="bab")  # or aba
    print(obj.longestPalindrome("cbbd")=="bb")