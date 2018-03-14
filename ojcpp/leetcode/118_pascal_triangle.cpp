//
// Created by Rui Zhou on 10/3/18.
//

/*https://leetcode.com/problems/pascals-triangle/description/
 * Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
  next row numbersis [1, sum of two neighbour number,1]

 10:26pm

 */

#include <codech/codech_def.h>
#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;


        for (int i=0;i<numRows;i++) {
            vector<int> tmp;
            int a=0;
            if (!result.empty()) {
                for (auto &iter: result.back()) {
                    tmp.push_back(a+iter);
                    a=iter;
                }
            }

            tmp.push_back(1);
            result.push_back(tmp);
        }
        return result;
    }
};

void printresult(const vector<vector<int>> &nums) {
    cout << " ===========================\n";
    for (auto &vec:nums) {
        cout << "[";
        for (auto &iter:vec) {
            cout << iter <<" ";
        }
        cout << "]"<<endl;
    }
}

DEFINE_CODE_TEST(118_pascaltriangle)
{
    Solution obj;
    printresult(obj.generate(0));

    printresult(obj.generate(5));

}