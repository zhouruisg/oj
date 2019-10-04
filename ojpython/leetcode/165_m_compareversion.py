        
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1_lst = version1.split('.')
        v2_lst = version2.split('.')
        for idx in range(max(len(v1_lst,v2_lst)):
            num1 = int(v1_lst[idx]) if idx<len(v1_lst) else 0
            num2 = int(v2_lst[idx]) if idx<len(v2_lst) else 0
            if num1<num2:
                return -1
            elif num1>num2:
                return 1
        return 0
        
obj=Solution()
#print(obj.findMedianSortedArrays([1,9,10],[]))