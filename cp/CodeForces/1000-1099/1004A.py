#Question: https://codeforces.com/problemset/problem/1004/A

a=list(map(int,input().split()))
t=a[0]
d=a[1]
arr=list(map(int,input().split()))
count=0
for i in range(t-1):
    if(arr[i+1]-arr[i]==2*d):
        count+=1
    elif(arr[i+1]-arr[i]>2*d):
        count+=2
print(count+2)
