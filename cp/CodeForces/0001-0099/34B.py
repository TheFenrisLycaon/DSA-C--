#Question: https://codeforces.com/problemset/problem/34/B

def solve(n, m, prices):
    prices.sort()
    total = 0
    for i in xrange(0, min(n, m)):
        if prices[i] >= 0:
            break
        total += prices[i]
    return -total

if __name__ == "__main__":
    n, m = map(int, raw_input().split(" "))
    prices = map(int, raw_input().split(" "))
    print solve(n, m, prices)
