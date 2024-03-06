n = int(input())
count = 0
for i in range(n):
    a = input()
    if (a.count("++")!=0):
         count = count+1
    else:
         count = count-1
print (count)

