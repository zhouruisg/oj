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
 假设T中没有重复字符串,很重要???
 1.使用移动窗口方法，先找到窗口的右侧，即index=5处， "ADOBEC"，然后缩减窗口的左侧，得到此时的substr len
 2.接着继续往右查找下一个窗口，index=10位置，"ADOBECODEBA"，从上一次的窗口左侧开始缩减
 技巧在于1,2步之间的状态转换，

窗口滑动
1.使用t.length()来表示找到了t中的所有字符，每找到一个字符就把对应的hashmap value-1,当到达窗口右侧的时候，
所有的value都应该是0
2.此时开始查找窗口左侧，窗口应在到达t中的任一个字符时停止移动.记下此时的start,计算出len


使用hash, key=t中每个char的个数，value=t的size为n，然后从头开始遍历，当所有的T都找到，找到n个字符，此时为窗口的右侧，
 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hm;
       for (auto c : t) {
           hm[c]++;
       }
       int num = t.length();
       for (int i=0;i<s.length();i++) {

       }


    }
};


DEFINE_CODE_TEST(076_minwindowsubstr)
{
    Solution obj;
    {
        cout << obj.minWindow("ADOBECODEBAANC","AAABC");
    }
    {
        obj.minWindow("ADOBECODEBANC","ABC");
    }

}