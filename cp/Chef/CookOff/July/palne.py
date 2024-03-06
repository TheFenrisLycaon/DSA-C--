for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    hash_map = {}
    for a in arr:
        if a in hash_map.keys():
            hash_map[a] += 1
        else:
            hash_map[a] = 1
        
    
    sol  = 0
    for key in hash_map.keys():
        sol+= min(key-1, hash_map[key])
    
    print(sol)