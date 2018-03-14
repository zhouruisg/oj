'''
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
https://leetcode.com/problems/combination-sum/description/
2:36 - 2:55
for each dfs, need create a copy of result(list)
'''

from collections import deque
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        out = set()
        arr = sorted(candidates, reverse=True)

        self.dfs([], target, arr, 0, out)

        outlst = []
        for tp in out:
            outlst.append(list(tp))
        return outlst

    def dfs(self, result, tg, arr, arridx, out):
        #print("looking",result, tg, arr[arridx:])
        for idx, val in enumerate(arr[arridx:]):
            gap = tg - val
            if gap == 0:
                l = list(result)
                l.append(val)
                #print("found!", l)
                out.add(tuple(sorted(l)))

            elif gap > 0:
                tmp = list(result)
                tmp.append(val)
                if self.dfs(tmp, gap, arr, idx+arridx, out):
                    #print("found!", tmp)
                    out.add(tuple(sorted(tmp)))

    def dfs1(self, result, tg, arr, arridx, out):
        print("looking",result, tg, arr[arridx:])
        for idx, val in enumerate(arr[arridx:]):
            gap = tg - val
            if gap == 0:
                #result.append(val)
                l = list(result)
                l.append(val)
                print("found!", l)
                out.add(tuple(sorted(l)))
                #return True
            elif gap > 0:
                tmp = list(result)
                tmp.append(val)
                if self.dfs(tmp, gap, arr, idx+arridx, out):
                    print("found!", tmp)
                    #print("use tmp:", tmp)
                    #result.extend(tmp)
                    #l = list(result)
                    #l.extend(tmp)
                    out.add(tuple(sorted(tmp)))


                    #return True
            #else:  # gap < 0
            #    return False
    '''
    def dfs0(self, result, tg, arr, arridx):
        if arridx >= len(arr):
            return False
        # print("looking",result, tg, arr[arridx:])

        for idx, val in enumerate(arr[arridx:]):
            gap = tg - val
            if gap == 0:
                result.append(val)
                # print("found!", result)
                return True
            elif gap > 0:
                result.append(val)
                return self.dfs(result, gap, arr, idx + arridx)
            else:  # gap < 0
                return False
    '''

def test():
    obj = Solution()
    #print(obj.combinationSum([2,3,6,7], 7))   #([7],[2,2,3])
    #print(obj.combinationSum([1], 2))  # ([1,1])
    #print(obj.combinationSum([1,2], 3))  # ([1,1,1],[1,2])
    print(obj.combinationSum([1, 2], 4))  # ([1,1,1,1],[1,1,2],[2,2])
    pass



if __name__ =='__main__':
    test()
