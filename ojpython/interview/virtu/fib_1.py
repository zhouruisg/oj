
def fib(n, val):
    a, b = 0, 1
    lastgap = 0
    for i in range(0, n):
        a, b = b, a + b
        #print(a,i)
        if a==val:
            return 0
        elif a > val:
            return min(lastgap,a-val)
        else:
            lastgap = val-a
    return -1


def solution(X):
    # write your code in Python 3.6
    return fib(1000000, X)



if __name__=="__main__":
    print(solution(15)==2)
    print(solution(13)==0)
    print(solution(0) == 0)
    print(solution(1) == 0)
    print(solution(4))



