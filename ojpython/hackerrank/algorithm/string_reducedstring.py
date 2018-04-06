# -*- coding: utf-8 -*-
'''
https://www.hackerrank.com/challenges/reduced-string/problem
Steve has a string of lowercase characters in range ascii[‘a’..’z’]. He wants to reduce the string to its shortest length by doing a series of operations in which he selects a pair of adjacent lowercase letters that match, and then he deletes them. For instance, the string aab could be shortened to b in one operation.

Steve’s task is to delete as many characters as possible using this method and print the resulting string. If the final string is empty, print Empty String

Input Format

A single string, .

Constraints

Output Format

If the final string is empty, print Empty String; otherwise, print the final non-reducible string.

Sample Input 0

aaabccddd
Sample Output 0

abd
Explanation 0

Sample Input

aaabccddd
Sample Output 0

abd
Explanation

Steve performs the following sequence of operations to get the final string:

aaabccddd → abccddd → abddd → abd
Sample Input 1

aa
Sample Output 1

Empty String
Explanation 1

Sample Input 1

aa
Sample Output 1

Empty String
Explanation 1

aa → Empty String
Sample Input 2

baab
Sample Output 2

Empty String
Explanation 2

Sample Input 1

baab
Sample Output 1

Empty String
Explanation 1

baab → bb → Empty String
'''

#!/bin/python3

import sys

def super_reduced_string(s):
    pos = 0
    while pos < len(s):
        if pos+1 < len(s):
            if s[pos] == s[pos+1]:
                s = s[:pos] + s[pos+2:]
                if pos != 0:
                    pos -= 1
            else:
                pos += 1
        else:
            break

    return "Empty String" if s == "" else s


def testcase():
    print("Empty String"==super_reduced_string("baab"))
    print("abd" == super_reduced_string("aaabccddd"))

    '''
    s = input().strip()
    result = super_reduced_string(s)
    print(result)
    '''

