//
// Created by rui zhou on 18/03/18.
//


/*
 * https://leetcode.com/contest/weekly-contest-76/problems/minimum-swaps-to-make-sequences-increasing/
 * We have two integer sequences A and B of the same non-zero length.

We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.

Example:
Input: A = [1,3,5,4], B = [1,2,3,7]
Output: 1
Explanation:
Swap A[3] and B[3].  Then the sequences are:
A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
which are both strictly increasing.
Note:

A, B are arrays with the same length, and that length will be in the range [1, 1000].
A[i], B[i] are integer values in the range [0, 2000].
 */

#include <codech/codech_def.h>


class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int l = A.size();
        int cur1=0,cur2=0;
        int step = 0;
        while (cur1!=l) {
            if (A[cur1] <= A[cur1+1]) {
                
            }
        }
    }
};

DEFINE_CODE_TEST(801_minimum_swap_make_sequence_increase)
{
    Solution obj;
    {
        vector<int> a{1,3,5,4};
        vector<int> b{1,2,3,7};
        VERIFY_CASE(obj.minSwap(a,b),1);
    }

    {
        vector<int> a{1,3,5,4};
        vector<int> b{1,2,3,7};
        VERIFY_CASE(obj.minSwap(a,b),1);
    }

}

/*
 * 802. Find Eventual Safe States
User Accepted: 173
User Tried: 316
Total Accepted: 174
Total Submissions: 602
Difficulty: Medium
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

Illustration of graph

Note:

graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].


 //======================================================================

 803. Bricks Falling When Hit
User Accepted: 4
User Tried: 40
Total Accepted: 4
Total Submissions: 85
Difficulty: Hard
We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.

We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.

Return an array representing the number of bricks that will drop after each erasure in sequence.

Example 1:
Input:
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
Output: [2]
Explanation:
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
Example 2:
Input:
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
Output: [0,0]
Explanation:
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.


Note:

The number of rows and columns in the grid will be in the range [1, 200].
The number of erasures will not exceed the area of the grid.
It is guaranteed that each erasure will be located inside the grid.
An erasure may refer to a location with no brick - if it does, no bricks drop.
 */