'''
/*
 * two non-negative integer N and M are called similar if their decimal representations without leading zero can be obtained from
 * each other by rearranging the digits. for example, in each of the followinf pairs, one integer is similar to the other:
 * 123 and 312
 * 52832 and 22835
 * 12 and 12
 * write function the get the number of similar integer
 */
don't use ang built-in func
4:58-

'''

import copy

result = set()


def solution(N):
    result.clear()
    lst = list(str(N))
    permutation(lst, 0)
    print(result)
    return len(result)


def permutation(lst, start):
    if start == len(lst) - 1:
        result.add(''.join(lst))
    else:
        for i in range(start, len(lst)):
            tmpLst = copy.deepcopy(lst)
            tmpLst[i], tmpLst[start] = tmpLst[start], tmpLst[i]
            permutation(tmpLst, start + 1)

    pass

if __name__ == '__main__':
    print(solution(123)==6)
    print(solution(121) == 3)
    print(solution(1213)==12)