//
// Created by rui zhou on 19/02/19.
//

/*
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false

 注意，本地没有010那种需要和前面的字母结合起来的关系
 a*   b*，完全可以分开 e.g. 匹配abbbbb
 */

#include <codech/codech_def.h>
using namespace std;

class Solution0 {
public:
    string s0,p0;
    bool doMatch(int si, int pj) {
        if (pj==p0.length()) {
            if (si==s0.length())
                return true;
            else
                return false;
        }

        if (p0[pj]=='?') {
            return doMatch(si+1,pj+1);
        } else if (p0[pj]=='*') {
            if (doMatch(si+1,pj))
                return true;
            else if (doMatch(si+1,pj+1))
                return true;
            else return doMatch(si,pj+1);
        } else if (s0[si]==p0[pj]) {
            return doMatch(si+1,pj+1);
        }
        return false;
    }

    bool isMatch(string s, string p) {
        s0=s;p0=p;
        return doMatch(0,0);
    }
};


class Solution {
public:
    string s0,p0;
    static const int FRONT=-1;
    bool doMatch(int si, int pj) {
        if (pj==FRONT) {
            if (si==FRONT)
                return true;
            else
                return false;
        }


        if (p0[pj]=='?') {
            return doMatch(si-1,pj-1);
        } else if (p0[pj]=='*') {
            if (doMatch(si-1,pj))
                return true;
            else if (doMatch(si-1,pj-1))
                return true;
            else return doMatch(si,pj-1);
        } else if (s0[si]==p0[pj]) {
            return doMatch(si-1,pj-1);
        }
        return false;
    }

    bool isMatch(string s, string p) {
        s0=s;p0=p;
        return doMatch(s.length()-1,p.length()-1);
    }
};



DEFINE_CODE_TEST(044_wildcard)
{
    Solution obj;
    {
        VERIFY_CASE(obj.isMatch("aa","a"),false);
        VERIFY_CASE(obj.isMatch("aa","*"),true);
        VERIFY_CASE(obj.isMatch("cb","?a"),false);
        VERIFY_CASE(obj.isMatch("adceb","*a*b"),true);
        VERIFY_CASE(obj.isMatch("acdcb","a*c?b"),false);
        VERIFY_CASE(obj.isMatch("","*"),true);  // 必须要考corner case

    }
}

