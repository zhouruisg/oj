//
// Created by rui.zhou on 2/13/2019.
//

/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 假设T中没有重复字符串,很重要
 用hash记录t中每个char的个数，t的size为n，然后从头开始遍历，当所有的T都找到，找到n个字符，此时为窗口的右侧，
 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        int num = t.size(), len=INT_MAX, start =0, left = 0;
        for(auto val: t) hash[val]++;
        for(int i =0; i < s.size(); i++)
        {
            if(hash[s[i]]-- >0) num--;
            while(num ==0)
            {
                len = (i-left+1)<len?(i-(start=left)+1):len;
                if(hash[s[left++]]++ ==0) num++;
            }
        }
        return len==INT_MAX?"":s.substr(start, len);
        return "";
    }
};


DEFINE_CODE_TEST(076_minwindowsubstr)
{
    Solution obj;
    {
        obj.minWindow("ADOBECODEBANC","ABC");
    }

}