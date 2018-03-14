'''
Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[ ["ate", "eat","tea"],
   ["nat","tan"],
   ["bat"]
]
leetcode 049
'''


class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        ret = []
        anagram = {}
        for el in strs:
            sel = ''.join(sorted(el))
            if sel in anagram:
                lst = anagram[sel]
            else:
                anagram[sel] = []
                lst = anagram[sel]
            lst.append(el)
        for key in anagram:
            ret.append(anagram[key])
        return ret


if __name__ == '__main__':
    print Solution().groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
