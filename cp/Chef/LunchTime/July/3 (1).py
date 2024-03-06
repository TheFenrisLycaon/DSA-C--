for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    # count = 0
    # for i in range(n):
    #     for j in range(n):
    #         if i != j:
    #             k = arr[i] - arr[j]
    #             if k / arr[i] < k / arr[j]:
    #                 count += 1
    # # print(count)
    res = [(x, y) for x in arr for y in arr if (x-y)**2 > 0]
    print(len(res))
