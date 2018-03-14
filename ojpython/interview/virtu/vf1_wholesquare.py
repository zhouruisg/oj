'''

 *Test: An integer P is a whole square if it is a square of some integer Q; i.e. if P = Q^2. Write a function:

Function solution( A, B);

that, given two integers A and B, returns the number of whole squares within the interval [A..B] (both ends included).

For example, given A = 4 and B = 17, the function should return 3, because there are three squares of integers in the interval [4..17],
namelv 4 = 2^2, 9 = 3^2 and 16 = 4^2 .
Assume that:

a. A and B are integers within the range [-10,000..10,000]; b. A <= B.
7:15-
'''

import math


def solution(a, b):
    if a < 0:
        a = 0
    if b < 0:
        return 0
    elif b == 0:
        return 1

    l = math.ceil(math.sqrt(a))
    u = int(math.sqrt(b))

    if l > u:
        return 0
    else:
        return u - l + 1
    pass



if __name__ == '__main__':
    print(solution(4, 17) == 3)
    print(solution(4, 25) == 4)
    print(solution(4, 24) == 3)
    print(solution(-4, 24) == 5)
