

s = input()

l = 'x'
s = l + s
m = 1
k = 1

for i in s:
    if i == l:
        k += 1
        if k > m:
            m = k
    else:
        l = i
        k = 1

if m >= 7:
    print("YES")
else:
    print("NO")
