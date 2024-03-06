#Question: https://codeforces.com/problemset/problem/11/A

import math
n,m=input().split()
n,m=int(n),int(m)
count=0
a=list(map(int,input().split()))
for i in range(n-1):
    if a[i]>=a[i+1]:   
           count+=math.ceil(((a[i]-a[i+1])+1)/m)
           a[i+1]+=m*math.ceil(((a[i]-a[i+1])+1)/m)        
print(count)            
    
