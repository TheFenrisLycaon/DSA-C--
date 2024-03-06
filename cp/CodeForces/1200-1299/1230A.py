#https://codeforces.com/problemset/problem/1230/A

def brut(s, i):
    if(s == (sum(lis)-s)):
        return 1
    if(i == 4):
        return 0

    return max(brut(s, i+1), brut(s+lis[i], i+1))


lis = list(map(int, input().split()))

if(brut(0, 0) == 1):
    print("YES")
else:
    print("NO")