n = int(input())
res = 0
max = 0
while n > 0:
    if n % 2 == 1:
        res += 1
        if res > max:
            max = res
    else:
        res = 0
    n //= 2
print(max)
