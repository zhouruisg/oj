//
// Created by rui.zhou on 10/1/2019.
//

/*
 * We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string S.  Return a list of strings representing all possibilities for what our original coordinates could have been.

Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".

The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)

Example 1:
Input: "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
Example 2:
Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation:
0.0, 00, 0001 or 00.01 are not allowed.
Example 3:
Input: "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
Example 4:
Input: "(100)"
Output: [(10, 0)]
Explanation:
1.0 is not allowed.


Note:

4 <= S.length <= 12.
S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.

 1.0 ->不允许，因为可以用1表示(更少的位数)
 01->不可以
 主要看string->double之后->string 能否等于原有的字符？
 主要是对条件的判断

 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        vector<string> ambiguousCoordinates(string S) {
            vector<string> ret;
            for (int i=1;i<S.size()-1;i++) {
                for (auto &left: f(S.substr(1,i))) {
                    for (auto &right: f(S.substr(i+1,S.size()-2-i))) { // (123)
                        ret.emplace_back("("+left+", "+right+")");
                    }
                }
            }
            return ret;
        }

        vector<string> f(string s) {
            vector<string> res;
            for(int i = 1; i <= s.size(); i++) {
                res.push_back(s.substr(0, i) + (i == s.size() ? "" : "." + s.substr(i)));
            }
            // check string
            //1.0 ,1.00

            return s.find_first_not_of("0")==string::npos && s.size()>1?vector<string>():  //没有非0字符并且size>1,e.g. 00->返回空
                        s[0]=='0' && s[s.size()-1]=='0' && s.size()>1?vector<string>():     // 头尾都是0,无法构成字符，返回空
                        s[s.size()-1]=='0'?vector<string>(1,s):                             // 最后一个字符是0,只能整体返回
                        s[0]=='0'? vector<string>(1,"0."+s.substr(1)):                      //  第一个字符是0, 返回0.xxxx
                        res;                                                                // 直接返回res即可
        }
    };
}