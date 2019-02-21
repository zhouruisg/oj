//
// Created by rui.zhou on 2/21/2019.
//

/*
 * Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */
#include <codech/codech_def.h>
using namespace std;

class Solution0 {
public:
    // too ugly and with problem!
    //一旦找到第一个char一样，就去比较下一个char,但这个时候必须记住第一个char的haystack的位置不能移动！
    int strStr(string haystack, string needle) {
        int lenh = haystack.length();
        int lenn = needle.length();
        if (lenn==0) return 0;
        if (lenn>lenh) return -1;

        int in=0;
        for (int i =0;i<lenh;i++) {
            if (needle[in]==haystack[i]) {
                if (in==lenn-1)
                    return i-lenn+1;
                else
                    in++;
            } else {
                in=0;
            }
        }
        return -1;
    }
};

class Solution {
public:
    // too ugly and with problem!
    //一旦找到第一个char一样，就去比较下一个char,但这个时候必须记住第一个char的haystack的位置不能移动！
    int strStr(string haystack, string needle) {
        int lenh = haystack.length();
        int lenn = needle.length();
        if (lenn==0) return 0;
        if (lenn>lenh) return -1;

        int in=0;
        for (int i =0;i<lenh;i++) {
            if (needle[in]==haystack[i]) {
                if (in==lenn-1)
                    return i-lenn+1;
                else
                    in++;
            } else {
                in=0;
            }
        }
        return -1;
    }
};

DEFINE_CODE_TEST(028_strstr)
{
    Solution obj;
    {
        VERIFY_CASE(obj.strStr("",""),0);
        VERIFY_CASE(obj.strStr("abc",""),0);
        VERIFY_CASE(obj.strStr("abc","a"),0);
        VERIFY_CASE(obj.strStr("abc","b"),1);
        VERIFY_CASE(obj.strStr("abc","d"),-1);
        VERIFY_CASE(obj.strStr("abc","abcde"),-1);
        VERIFY_CASE(obj.strStr("abc","abc"),0);
        VERIFY_CASE(obj.strStr("aaaaa","bba"),-1);
        VERIFY_CASE(obj.strStr("hello","ll"),2);
        VERIFY_CASE(obj.strStr("mississippi","issip"),4);

    }
}