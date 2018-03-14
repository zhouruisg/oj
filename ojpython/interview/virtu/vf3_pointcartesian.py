'''
/*
 * a point in a tw-dimensional cartesian plane is called a lattice point if both of its coordinates are integers
 * write a function:

* int solution(int N):
 * given a non-negative integer N,returns the number of lattice points lying inside or on the edge of a disc of
 * radius N which is centered at (0,0) the function should return -1 if this number exceeds 1,000,000,000
 * for example, given N=2, the function should return 13, because there are thirteen points
 * lying inside or on the edge of disc of radius 2centered at (0,), as indicated in the following image
 *
 * raidus - 2,
 *
 * assume that:
 * N is an integer within the range[0..20000]
 * complexity:
 * expetced worst-case time complexity is O(N)
 * expected worst space complexity is O(1)
 *
 */
 12:00

 find the square size, check N-1 to 1, which is inside the circle
'''

import math

def solution(n):
    m = 0
    for i in range(n-1, 0, -1):
        l = math.sqrt(2*(i**2))
        if l<n:
            m = i
            break

    h = 0
    for j in range(m+1,0,-1):
        k = math.sqrt((m+1)**2+j**2)
        if k < n:
            h = j
            break

    total = (m*2+1)**2
    total += (h*2+1)*4
    return total



if __name__ == '__main__':
    print(solution(1) == 5)
    print(solution(2) == 13)
    print(solution(6) == 109)
