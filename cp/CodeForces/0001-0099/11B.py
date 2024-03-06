n = int(input(""))

def sum(x):
    return x * (x + 1) / 2

if n < 0:
    n = -n

ans = 0
while 1:
    s = sum(ans)
    if (s - n) % 2 > 0 or (s < n):
        ans += 1
    else:
        break

print(ans)