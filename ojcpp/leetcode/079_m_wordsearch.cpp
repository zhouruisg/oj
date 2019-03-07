//
// Created by rui zhou on 07/03/19.
//

/*
 * https://leetcode.com/problems/word-search/
 * Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

 */

#include <codech/codech_def.h>

using namespace std;
namespace lc079 {
    class Solution {
    public:
        void dfs(int x,int y,int pos) {

        }

        bool exist(vector<vector<char>>& board, string word) {
            if (board.empty() || word.empty())
                return false;
            int m=board.size();
            int n=board[0].size();
            vector<vector<bool>> visited(m,vector<bool>(n,false));
            int pos=0;
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (board[i][j]==word[pos]) {

                    }
                }
            }
        }
    };
}

DEFINE_CODE_TEST(106_buildbt_inpostorder)
{
    Solution obj;
    {
        vector<int> p{9,15,7,20,3},i{9,3,15,20,7};
        VERIFY_CASE(TREE_PREORDER(obj.buildTree(i,p)),"3 9 20 15 7");
    }

}