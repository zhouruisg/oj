'''
/*
 * a sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between
 * any two consecutive elements is the same, for example, these are arithmetic swquences:
 * 1,3,5,7,9
 * 7,7,7,7,7
 * 3,-1,-5,-9
 * the sequence[1,1,2,5,7] is not arithmetic

 * a zero-indexed array a consisting of N numbers is given, a slice of the array is any pair of integers
 * (P,Q) such that 0 <= P < Q < N
 * a slice (P,Q) of array A is called arithmetic if the sequence:
 * A[P],A[P+1],...A[Q-1],A[Q]
 * is arithmetic, in particular, this means that P+1 < Q
 * write a function:
 * int solution(int A[],int N)
 * that,given array A consisting of N numbers, return the number of arithmetic slice in A
 * the function should return -1 if the result exceeds 1,000,000,000
 *[-1,1,3,3,3,2,1,0]
 *the function should return 5 because there are five arithmetic slices of that array, namely:
 *(0,2),(2,4),(4,6),(4,7),(5,7)
 *
 *

 * O(N)
 *
 */

find all the arithmetic sequence from a array, return as (begin, end) pair
 10:11-10:45
'''

def solution(nums):
    # 1,2,3,4,5....-->n=3,4,5,6,7
    # -> 1+2+3+4 when n=6
    def calc(n):
        return (n-1)*(n-2)/2

    if len(nums) < 3:
        return 0

    step = nums[1]-nums[0]
    begin = 0
    end = 1
    count = 0

    for cur in range(2, len(nums)):
        if nums[cur]-nums[end] == step:
            end+=1
        else:
            count += calc(end-begin+1)
            begin = end
            end = cur
            step = nums[cur] - nums[begin]
    count += calc(end - begin + 1)
    return count


if __name__ == '__main__':
    print(solution([1,1,2,5,7])==0)
    print(solution([-1,1,3,3,3,2,1,0])==5)
    print(solution([7,7,7,7])==3)