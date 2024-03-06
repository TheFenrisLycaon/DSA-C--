import sys


def maximumPoints(k, costs):
    s = res = fin = 0

    mx = -1
    flag = 0

    for i in range(len(costs)):
        s += costs[i]
        mx = max(mx, costs[i])
        if s <= k:
            res += 1
        if not flag and s > k:
            fin = res
            s -= mx
            flag = 1

        elif flag and s > k:
            break

    return max(res, fin)


k = int(input().strip())

costs_count = int(input().strip())

costs = []

for _ in range(costs_count):
    costs_item = int(input().strip())
    costs.append(costs_item)

result = maximumPoints(k, costs)

print(result)
