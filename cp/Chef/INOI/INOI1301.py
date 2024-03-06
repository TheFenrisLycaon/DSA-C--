__MAX__ = -10000000000

def forw(dpF, a, k):
    if(k == len(a)-1):
        return
    n = len(dpF)
    dpF[1] = a[k+1]
    for i in range(2, n):
        dpF[i] = a[k+i] + max(dpF[i-1], dpF[i-2])


def back(dpB, a):
    n = len(dpB)
    dpB[1] = a[0]
    for i in range(2, n):
        dpB[i] = max(dpB[i-1]+a[i-1], dpB[i-2]+a[i-2])


n, k = map(int, input().split())
a = list(map(int, input().split()))

dpF = [0]*(n-k+1)
dpB = [0]*n

forw(dpF, a, k-1)
back(dpB, a)


for i in range(k-1, n):
    sum = dpF[i-k+1] + dpB[i]
    if(sum > __MAX__):
        __MAX__ = sum

print(__MAX__)
