def collatz(n):
    length = 1
    nList = []
    nList.append(n)
    while n != 1:
        if n not in dic:
            n = rule(n)
            nList.append(n)
            length += 1
        else:
            nList.extend([None for _ in range(dic[n] - 1)])
            length = (length - 1) + dic[n]
            break
    for seq in nList:
        if seq not in dic:
            dic[seq] = len(nList) - nList.index(seq)
    return length


def rule(n):
    if n % 2 == 0:
        return n // 2
    else:
        return 3 * n + 1
    
def solve(m):
    longestLen = 0
    longestNum = 0
    for n in range(2, m):
        prsntLen = collatz(n)
        if prsntLen > longestLen:
            longestLen = prsntLen
            longestNum = n
    return longestNum

dic = {}
print(solve(5))
print(solve(10))
