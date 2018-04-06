# -*- coding: utf-8 -*-
'''
https://www.hackerrank.com/challenges/maximum-palindromes/problem
'''

#!/bin/python3

import sys
mod = (10**9)+7
fact = []
infact =[]
S = []
def exp(a,b,mod):
    ans = 1
    while(b!=0):
        if((b%2)== 1):
            ans = (ans*a)%mod
        a = (a*a)%mod
        b>>=1
    return ans

def initialize(s):
    # This function is called once before all queries.
    global mod,fact,infact,S
    fact = [1]*((10**5) +1)
    for i in range(1,(10**5) + 1):
        fact[i]= (i*fact[i-1])%mod  # factorial result

    infact = [0]*((10**5) +1)
    infact[-1]= exp(fact[-1],mod-2,mod)

    for i in range((10**5)-1,-1,-1):
        infact[i] = ((i+1)*infact[i+1])%mod

    l = len(s)

    for i in s:
        S += [[0]*26]
        S[-1][ord(i)-97]=1

    for i in range(1,l):
        for j in range(26):
            S[i][j]+=S[i-1][j]

def answerQuery(s,l, r):
    global mod
    temp = [0]*26
    for i in range(26):
        temp[i]=S[r][i]-S[l][i]
    temp[ord(s[l])-97]+=1
    tot = 0
    one = 0
    ans = 1
    for i in temp:
        one += i%2
        tot += i//2
        ans = (ans*infact[i//2])%mod
    ans = (ans*fact[tot])%mod
    if(one!=0):
        ans = (ans * one)%mod
    return ans

if __name__ == "__main__":
    '''s = raw_input().strip()
    initialize(s)
    q = int(raw_input().strip())
    for a0 in xrange(q):
        l, r = raw_input().strip().split(' ')
        l, r = [int(l), int(r)]
        result = answerQuery(s,l-1, r-1)
        print(result)
    '''
    pass


def testcase():
    s = "week"
    initialize(s)
    print(answerQuery(s, 1-1, 4-1))

