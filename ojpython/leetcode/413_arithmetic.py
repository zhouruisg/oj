'''
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.
'''

'''
DP

class Solution {    
    // 2nd round        date: 2016-10-15        location: Vista Del Lago III Apartement
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)   return 0;
        vector<int> dp(A.size(), 0);
        int res = 0;
        for (int i = 2; i < A.size(); i ++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                dp[i] = dp[i - 1] + 1;
            res += dp[i];
        }
        return res;
    }
};
'''

class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        def calc(n):
            return (n - 1) * (n - 2) / 2

        if len(A) < 3:
            return 0

        step = A[1] - A[0]
        begin = 0
        end = 1
        count = int(0)

        for cur in range(2, len(A)):
            if A[cur] - A[end] == step:
                end += 1
            else:
                count += calc(end - begin + 1)
                begin = end
                end = cur
                step = A[cur] - A[begin]
        count += calc(end - begin + 1)
        return count

if __name__ == '__main__':
    obj=Solution()
    print(obj.numberOfArithmeticSlices([1, 1, 2, 5, 7]) == 0)
    print(obj.numberOfArithmeticSlices([-1, 1, 3, 3, 3, 2, 1, 0]) == 5)
    print(obj.numberOfArithmeticSlices([7, 7, 7, 7]) == 3)