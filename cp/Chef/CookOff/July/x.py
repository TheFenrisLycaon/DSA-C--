from math import *
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    half =  len(arr)//2
    m = max(arr)
    x =0 
    i = 1
    while i <= m:
        count = 0 
        for n in arr:
            if n^i == 0 :
                count+=1
        if count>half:
            x+=i
        i*=2
    
    mi = 0
    for n in arr:
        mi = mi | (n^x)

    print(x,mi)