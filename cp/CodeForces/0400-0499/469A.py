n=int(input())
a=list(map(int, input().split()))[1:]
b=list(map(int, input().split()))[1:]
c=a+b
m=len(set(c))
print(list(set(c)))
i=1
count=0
while (i != m-1):
    if (list(set(c))[i] == i):
        count = count+1
    i=i+1       
if (count >= 1):
    print ("I become the guy.")
else:
    print ("Oh, my keyboard!")

