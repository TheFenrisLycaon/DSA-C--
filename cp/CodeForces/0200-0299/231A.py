n = int(input())
count = 0
for i in range(n):
    a = list(map(int, input().strip().split( " ")))        
    if a[0]+a[1]+a[2] >= 2:
        count = count + 1
print (count)
        
       
