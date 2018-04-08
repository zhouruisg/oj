//
// Created by Rui Zhou on 6/4/18.
//

/*
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.


 * */

/*
 * int tot = 1;
        for (int i=0;i<digits.length();i++) {
            if (!m[digits[i]-'0'].empty())
                tot *= m[digits[i]-'0'].length();
        }
        vector<string> ret(tot,"");
        for (int i=0;i<digits.length();i++) {
            string &pc = m[digits[i]-'0'];
            int p = pc.length();
            if (p==0)
                continue;
            int num = tot;
            int offset = 0;
            for (int k=0;k<num;k++) {
                for (int j=0; j< p ; j++) {
                    ret[offset+j] +=  pc[j];
                }
                offset += p;
            }
        }
 */
#include <codech/codech_def.h>
#include <codech/algo_common.h>
using namespace std;
using namespace CODECH;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> m{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ret;
        next(m, digits, ret, "", 0);
        return ret;
    }

    void next(vector<string> &m, string & digits, vector<string> &ret, string comb, int mi) {
        if (mi >=digits.size() ) {
            if (!comb.empty())
                ret.push_back(comb);
            return;
        }

        string &ms = m[digits[mi]-'0'];
        if (ms.empty()) {
            next(m, digits, ret, comb, mi+1);
        } else {
            for (int i=0; i < ms.length(); i++) {
                next(m, digits, ret, comb+ms[i], mi+1);
            }
        }

    }
};

DEFINE_CODE_TEST(017_lettercombination_phoneletter)
{
    Solution obj;
    {
        //ad ae af
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("123")),"ad ae af bd be bf cd ce cf ");
    }
    {
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("23")),"ad ae af bd be bf cd ce cf ");
    }
    {
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("0"))," ");
    }
    {
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations(""))," ");
    }
    {
        VERIFY_CASE(PRINT_STRVEC(obj.letterCombinations("1234567890")),"");
    }

}