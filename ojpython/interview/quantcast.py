'''
Reverse words in a string. "This is a girl" becomes "girl a is This".
'''


def reverse_string(s):
    s1 = s.split(' ')
    s2 = ' '.join(s1[::-1])
    return s2


'''
 Calculate nth Fibonacci number. Optimize it.
n[0]=0,n[1]=1,f(n)=f(n-1)+f(n-2)
1 1 2 3 5 8 13...
'''

def fibonacci0(n):
    pos = 2
    f0 = 0
    f1 = 1
    if n == 0:
        return f0
    elif n == 1:
        return f1
    while pos <= n:
        f = f0+f1
        pos +=1
        f0 = f1
        f1 = f
    return f

def fibonacci(n):
    pos = 2
    f0 = 0
    f1 = 1
    if n == 0:
        return f0
    elif n == 1:
        return f1
    while pos <= n:
        f = f0+f1
        pos += 1
        f0 = f1
        f1 = f
    return f
'''
def test_fib():
    for i in range(10):
        print i, ":", fibonacci(i)
    pass
'''
'''
Given a sorted list that has two of each integer except one, find the one integer that does not occur in the list twice
sorted? 1,1,2,2,3,3,4,5,5 ->easy
not sorted? ->hht_offer
'''
#sorted array
def occur_once(arr):
    if len(arr) == 0:
        return 0
    length = len(arr)
    for idx in range(0, length, 2):
        if idx != length-1:
            if arr[idx] != arr[idx+1]:
                return arr[idx]
        else:
            return arr[idx]
    return 0

'''
Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[ ["ate", "eat","tea"],
   ["nat","tan"],
   ["bat"]
]
leetcode 049
'''

'''
Find kth largest number from stream of numbers and discuss performance in O notation.
see hht_offer find_median or nth_element
sort(), then find kth O(NLogN)
partition->O(N)
'''

'''
find and remove all the duplicates in the array(unsorted)
leetcode 026
(1)sort->unique
(2)

'''

'''
#
# Find the size of the largest possible set that sums to less than K

# Input:
# int array[] = [50, 2, 3, 7, 8, 11, 1, 33]
# int k = 3;
# return 1; # (1) (2)

# int k = 6;
# return 2; (2,3) (1,2) (1,3)
#

def largest_set(arr, k):
    if not arr or k < 0:
        return 0
    sarr = sorted(arr)
    large_num = 0
    ksum = 0
    for i in range(0, len(sarr)):
        if ksum + sarr[i] >= k:
            return large_num
        else:
            ksum += sarr[i]
            large_num += 1
    return large_num

if __name__ == '__main__':
    print(largest_set([50,2,3,7,8,11,1,33],3))
    print(largest_set([50,2,3,7,8,11,1,33],6))

#N*LogN

#--------
# real question
#
# Find the size of the largest possible set that sums to less than K

# Input:
# int array[] = [50, 2, 3, 7, 8, 11, 1, 33]
# int k = 3;
# return 1; # (1) (2)

# int k = 6;
# return 2; (2,3) (1,2) (1,3)
#

def largest_set(arr, k):
    if not arr or k < 0:
        return 0
    sarr = sorted(arr)
    large_num = 0
    ksum = 0
    for i in range(0, len(sarr)):
        if ksum + sarr[i] >= k:
            return large_num
        else:
            ksum += sarr[i]
            large_num += 1
    return large_num

if __name__ == '__main__':
    print(largest_set([50,2,3,7,8,11,1,33],3))
    print(largest_set([50,2,3,7,8,11,1,33],6))

#N*LogN
'''

# do in O(n)
import heapq   #minheap
def size_largest_set(arr, k):
    h = []
    hsum = 0

    if not arr or k < 0:
        return 0

    for el in arr:
        if el < k:
            if el + hsum < k:
                heapq.heappush(h, -el)
                hsum += el
            else:
                popitem = heapq.heappushpop(h, -el)
                hsum = hsum - (-popitem) + el
    return len(h)


if __name__ == '__main__':
    print(reverse_string("This is a girl")=="girl a is This")
    print(fibonacci(3) == 2)
    print(fibonacci(4) == 3)
    print(size_largest_set([50,2,3,7,8,11,1,33], 3) == 1)
    print(size_largest_set([50, 2, 3, 7, 8, 11, 1, 33], 6) == 2)
    #print(occur_once([1,1,2,2,3,3,4,5,5]))
