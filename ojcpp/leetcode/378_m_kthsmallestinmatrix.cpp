//
// Created by rui.zhou on 2/7/2019.
//
/*
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
 矩阵的行和列都是有序的，因此左上角最小，右下角最大
 */

#include <codech/codech_def.h>
#include <tuple>

using namespace std;

class Solution {
public:
    //m=n*n
    //m*log(m)*m
    int kthSmallest0(vector<vector<int>>& matrix, int k) {
        vector<int> arr;
        //O(M)
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                arr.push_back(matrix[i][j]);
            }
        }
        //M*log(M)
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }

    // 思路 利用优先级队列，从左上角开始push进队列，

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<tuple<int,int,int>> q;
        int n=matrix.size();
        for (int row=0;row<n;row++) {
            auto el = std::make_tuple(matrix[row][0],row,0);
            q.push(el);
        }
        for (int j=0;j<k;j++) {
            int v,row,col;
            std::tie(v, row, col) = q.top();
            q.pop();

        }
        return q.top();
    }
};

