# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # write your code in Python 3.6
    hexstr = "%X" % int(S)
    encode = {'1':'I','0':'O','A':'A','B':'B','C':'C','D':'D','E':'E','F':'F'}

    lst = list(hexstr)
    #print(lst)
    result = []
    for c in lst:
        if c in encode:
            result.append(encode[c])
        else:
            #print(c)
            return "ERROR"

    return ''.join(result)

if __name__=="__main__":
    print(solution(257)=="IOI")
    print(solution(3)=="ERROR")



