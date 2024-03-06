res = []
for _ in range(int(input())):
    x = list(map(int, input().split()))
    s = input()
    sasc = list(map(ord, list(s)))
    sasc[:] = [number - 96 for number in sasc]
    num = int(''.join(list(map(str, sasc))))
    k = (sasc[-1]+ sasc[-1]-1) // 2
    print(k)
    
    # snum = sum(list(map, ord()))
