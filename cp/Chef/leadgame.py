lead = 0
leader = -1
for _ in range(int(input())):
    x, y = map(int, input().split())
    if lead < abs(y - x):
        if y > x:
            leader = 2
            lead = y - x
        else:
            lead = x - y
            leader = 1

print(leader, lead)
