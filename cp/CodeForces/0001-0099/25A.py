#Question: https://codeforces.com/problemset/problem/25/A

n = int(input())
l = []
l.append(input().split(" "))
count = 0
sum = 0
for i in range (n):
    if int(l[0][i]) % 2 == 0:
        count = count + 1
    else :
         a = i
if count >= 2:
    print (a+1)
else:
    for i in range(n):
        if int(l[0][i]) %2 != 0:
            sum = sum +1
        else :
            b = i
if sum >= 2:
    print (b+1)         

    
    
    
        
