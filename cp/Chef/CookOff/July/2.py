from math import gcd

for _ in range(int(input())):
    num = list(map(int, input().split()))
    count = 0
    if num[0]%2 ==0 and num[1]%2==0:
        count = 0 
    elif gcd(num[0]+1, num[1])>1 or gcd(num[0], num[1]+1)>1:
        count += 1
    else:
        count+=2
    print(count)