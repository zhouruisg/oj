//
// Created by Rui Zhou on 7/4/18.
//

/*
 * https://leetcode.com/problems/unique-paths/description/
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
 */

#include <codech/codech_def.h>
#include <unordered_set>

using namespace std;

namespace std {
    template<>
    struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };
}
void printset(unordered_set<pair<int,int>>&pos) {

}
class Solution {
public:
    /*int uniquePaths0(int m, int n) {
        unordered_set<pair<int,int>> pos;
        return move(pos, m,n,1,1);
    }

    int move0(unordered_set<pair<int,int>>&pos, int m, int n, int x, int y) {
        auto iter = pos.find(make_pair(x,y));
        if (iter != pos.end())
            return 0;

        if (x>n || y>m || x ==0 || y==0) {
            return 0;
        }
        if (x==n && y==m) {

            return 1;
        }
        pos.insert(make_pair(x,y));
        int right = move(pos,m,n,x+1,y);
        //int left =  move(pos,m,n,x-1,y);
        //int up =  move(pos,m,n,x,y-1);  //only down or right
        int down = move(pos,m,n,x,y+1);
        pos.erase(make_pair(x,y));
        return right+down;  //left+up+
    }*/

    // TLE
    int uniquePaths1(int m, int n) {
        return move(m,n,1,1);
    }
    int move(int m, int n, int x, int y) {
        if (x>n || y>m || x ==0 || y==0) {
            return 0;
        }
        if (x==n && y==m) {

            return 1;
        }

        int right = move(m,n,x+1,y);
        int down = move(m,n,x,y+1);

        return right+down;  //left+up
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,1));
        for (int i=n-1; i >0; i--) {
            for (int j = m-1; j >0 ; j--) {
                dp[j][i] = dp[j+1][i]+dp[j][i+1];
            }
        }
        return dp[1][1];
    }

};

DEFINE_CODE_TEST(062_uniquepath)
{
    Solution obj;
    {
        VERIFY_CASE(obj.uniquePaths(2,2),2);
    }
    {
        VERIFY_CASE(obj.uniquePaths(3,3),6);
    }
    {
        VERIFY_CASE(obj.uniquePaths(23,12),193536720);
    }

}