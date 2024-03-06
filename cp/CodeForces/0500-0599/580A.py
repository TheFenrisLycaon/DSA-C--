n = int(input())
l = list(map(int, input().split()))
count = 1
large = 0
b = []
for i in range(len(l)-1):
    if (l[i] <= l[i+1]):
        count = count + 1
        if (count >=large):
            large = count
    else:
        count=1
if (n <= 1 or large == 0):
    print (1)
else:
    print(large)  
     
