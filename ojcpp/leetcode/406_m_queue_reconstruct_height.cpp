//
// Created by rui zhou on 11/03/19.
//

/* greedy
 * Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

#include <codech/codech_def.h>
using namespace std;

// 按height 降序排列，同样的height按k升序排列，因为比较的是
// 很难想出这个插入法。

namespace lc406 {
    class Solution {
    public:
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
            

        }
    };
}




