for _ in range(int(input())):
    shoes = list(map(int, input().split()))
    if sum(shoes) >= 1 and sum(shoes) < 3:
        print(1)
    else:
        print(0)
