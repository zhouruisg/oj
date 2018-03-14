"""
Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

"ckilbkd" - > 5
use a dict to remember the start position

"""



class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lss = {}
        maxlen = start = 0
        for pos, c in enumerate(s):
            if c not in lss:
                lss[c] = pos
                maxlen = max(maxlen, pos - start + 1)
            else:
                # handle two cases here!!!
                if lss[c]<start:
                    maxlen = max(maxlen, pos - start +1)
                else:
                    maxlen = max(maxlen, pos - start)
                    start = lss[c] + 1
                lss[c] = pos
        return maxlen



if __name__ == '__main__':
    obj = Solution()
    print(obj.lengthOfLongestSubstring("abba")==2)
    print(obj.lengthOfLongestSubstring("tmmzuxt")==5)
    print(obj.lengthOfLongestSubstring("abcabcbb")==3)  # 3
    print(obj.lengthOfLongestSubstring("bbbbb")==1)
    print(obj.lengthOfLongestSubstring("pwwkew")==3)
    print(obj.lengthOfLongestSubstring("ckilbkd")==5)
    print(obj.lengthOfLongestSubstring("ckilbkilbopd")==7)
    print(obj.lengthOfLongestSubstring("ggububgvfk")==6)
