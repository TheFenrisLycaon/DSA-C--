n = int(input())
s = input().split(" ")
ss = list(map(int, s))

ans = 0
i = 0
k = []
while i < n:
    if s[i] in k or ss[i] > n:
        ans += 1                    
    else:
        k.append(s[i])
    i += 1

print(ans)