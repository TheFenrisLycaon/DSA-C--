a = list(map(int, input().strip().split()))
l = 0
for i in range(1,a[2]+1):
    l = l + (i * a[0])
if l<=a[1]:
    print("0")
else:
    print ((l - a[1]))
