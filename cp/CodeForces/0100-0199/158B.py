n = int(input(""))
s = input("").split(" ")
s.sort(reverse=True)
# s = [int(i) for i in s]
s = list(map(int, s))
ans = 0
i = 0
j = len(s) - 1
while i <= j:
    ans += 1
    four = 4 - s[i]
    while (s[j] <= four) and (j >= i):
        four -= s[j]
        j -= 1
    i += 1
print(ans)