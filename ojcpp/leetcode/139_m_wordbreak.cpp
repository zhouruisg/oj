//
// Created by rui.zhou on 3/10/2019.
//

/*
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
 */

#include <codech/codech_def.h>
using namespace std;

namespace lc139 {
    // TLE 递归的方法
    // 经过剪枝后通过，使用一个set来排除无法通过的string
    class Solution {
    public:
        bool dfs(unordered_set<string> &nomatch,string s, vector<string>& wordDict) {
            int wordLength=0;
            if (s.empty())
                return true;
            if (nomatch.count(s))
                return false;

            for (auto &iter:wordDict) {
                if (s.find(iter)==0) {
                    wordLength=iter.length();
                    string piece=s.substr(wordLength);
                    if (dfs(nomatch,piece,wordDict))
                        return true;
                }
            }
            nomatch.insert(s);
            return false;
        }
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> nomatch;
            return dfs(nomatch,s,wordDict);
        }
    };

    //DP
//    Set ws = new HashSet<>(wordDict);
//    boolean[] dp = new boolean[s.length()+1];
//    dp[s.length()] = true;
//    for(int i=s.length(); i>0; i--){
//    if(dp[i]){
//    for(int j=i-1;j>=0;j--){
//    dp[j] = dp[j] || ws.contains(s.substring(j,i));
//    if(dp[0]) return true;
//}
//}
//}
//return dp[0];
//}
    // 思路, 从左往右匹配，dp[n] 记为从1字符起到n字符的匹配情况。dp[0]作为占位符
    class Solution1 {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(),wordDict.end());
            vector<int> dp(s.length()+1,0);
            dp[0]=1;
            for (int i=1;i<=s.length();i++) {
                for (int j=0;j<i;j++) {
                    if (dp[j] && dict.count(s.substr(j,i-j))) {
                        dp[i]=1;
                        break;
                    }
                }
            }
            return dp[s.length()];
        }
    };
}

DEFINE_CODE_TEST(139_wordbreak)
{
    lc139::Solution1 obj;
    {
        vector<string> dict{"leet", "code"};
        VERIFY_CASE(obj.wordBreak("leetcode",dict),true);
    }
    {
        vector<string> dict{"cats", "dog", "sand", "and", "cat"};
        VERIFY_CASE(obj.wordBreak("catsandog",dict),false);
    }
    {
        vector<string> dict{"apple", "pen"};
        VERIFY_CASE(obj.wordBreak("applepenapple",dict),true);
    }
    {
        vector<string> dict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        VERIFY_CASE(obj.wordBreak("\"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\"",dict),false);

    }
}