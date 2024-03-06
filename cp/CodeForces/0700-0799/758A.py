n = int(input())
a = []
a = list(map(int, input().strip().split()))
b = 0
for i in range (len(a)):
    b = max(a)-a[i] + b
print (b)
