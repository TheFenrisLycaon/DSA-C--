for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))

    hashMap = {}
    for i in arr:
        if i in hashMap.keys():
            hashMap[i]+=1
        else:
            hashMap[i] = 1
    sol = 0
    for key in hashMap.keys():
        sol += hashMap[key] * (n - hashMap[key])
    
    print(sol)