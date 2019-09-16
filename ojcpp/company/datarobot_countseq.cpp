//
// Created by rui.zhou on 2019/9/11.
//
/*
 * you are the apple of my eye
 * the apple of my eye you are  --->5
 * the apple you are the apply of my eye  -> 6   [the apple of my eye -->5]
 * lc1143
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    bool longestCommonSubsequence(string txt1, string txt2) {
        std::istringstream iss(txt1);
        std::vector<std::string> vt1{std::istream_iterator<std::string>(iss), {}};
        std::vector<std::string> vt2{std::istream_iterator<std::string>(iss), {}};

        vector<vector<int>> dp(vt1.size()+1, vector<int>(vt2.size()+1,0));
        for(int i=0;i<vt1.size();i++) {
            for(int j=0;j<vt2.size();j++){
                if(vt1[i]==vt2[j]) {
                    dp[i+1][j+1]=dp[i][j]+1;
                } else {
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[vt1.size()][vt2.size()];
    }
}





