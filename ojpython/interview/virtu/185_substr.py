def solution(S):
    # write your code in Python 3.6
    result = []
    begin = 0
    end = 0
    for idx in range(1, len(S)):
        if (S[idx]==S[idx-1]):
            end+=1
        else:
            result.append(S[begin:end+1])
            begin = idx
            end = idx

    result.append(S[begin:end + 1])
    print(result)
    sum = 0
    for el in result:
        sum+=(1+len(el))*len(el)//2

    return sum


if __name__=="__main__":
    print(solution("zzzyz"))