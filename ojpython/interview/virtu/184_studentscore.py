# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

from copy import deepcopy
def solution(A):
    # write your code in Python 3.6
    change = True
    while change:
        change = False
        l = deepcopy(A)
        for idx in range(1,len(A)-1):
            if A[idx] > A[idx-1] and A[idx] > A[idx+1]:
                l[idx] -= 1
                change = True

            if A[idx] < A[idx - 1] and A[idx] < A[idx + 1]:
                l[idx] += 1
                change = True

        A = l
    return A
    pass


if __name__=="__main__":
    print(solution([1,6,3,4,3,5]))
    print(solution([100,50,40,30]))




