//
// Created by rui.zhou on 2/15/2019.
//
/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
1.使用DP,用一个table来表示当前的状态,dp[i][j]=true表示start=i,end=j的字串为回文
2.遍历s,对于每个字符，再从0,i进行遍历dp,如果某字符串是回文，那么去掉头尾他仍然是回文,如果头尾相等也是回文
3. 比较浪费的是每次都要从头开始比较，因为不知道前一个字符能形成的回文起始点在哪里。
 */
#include <codech/codech_def.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1000][1000]= {false};
        int start = 0;
        int maxlen = 1;
        for (int i=0;i<s.length();i++) {
            dp[i][i]=true;
            for (int j=0;j<i;j++) {
                dp[j][i] = (s[j]==s[i] && i-j==1) || (s[j]==s[i] && dp[j+1][i-1]==true );
                if (dp[j][i] && maxlen<(i-j+1)) {
                    maxlen = i-j+1;
                    start=j;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};

DEFINE_CODE_TEST(005_longestpalindrome) {
    Solution obj;
    {
        string s = "babad";
        VERIFY_CASE(obj.longestPalindrome(s),"bab");
    }
    {
        string s = "cbbd";
        VERIFY_CASE(obj.longestPalindrome(s),"bb");
    }
}
