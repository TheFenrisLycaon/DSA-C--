a, b = map(int, input().split())
c=a//b
if (a%2 == 0 and b%2 == 0):
    print (c+a)
else:
    print(c+a+1)
