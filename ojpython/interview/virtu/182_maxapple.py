# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    capacity = 5000-A[0]
    apples = sorted(A[1:])
    sum = 0
    total = 0
    for idx,a in enumerate(apples):
        if a+sum > capacity:
            total = idx
            break
        else:
            sum+=a

    return total



if __name__=="__main__":
    print(solution([4650,150,150,150])==2)
    print(solution([4850,100,30,30,100,50,100]) == 3)
