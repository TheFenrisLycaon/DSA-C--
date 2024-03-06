n, d = map(int, input().split())
prices = sorted(list(map(int, input().split())))

count = 0

while d > 0:
    for i in prices:
        d -= i
        if d <= 0:
            break
        count += 1

print(count)
