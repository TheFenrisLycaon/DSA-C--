n=int(input())
for i in range (len(n)):
    if (i == 7 or i == 4):
        print("YES")
if ( n%7 == 0 or n%4==0):
    print ("YES")
else :
    print ("NO")
print (n)
