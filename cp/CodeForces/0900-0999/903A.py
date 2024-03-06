n = int(input())
l = []
for i in range (n):
    l.append(int(input()))
for i in range (len(l)):
    if (l[i]%7 == 0 or l[i]%3 == 0 or l[i] == 10):
        print ("YES")     
    elif l[i] > 11  :
        print ("YES")
    else :
        print ("NO")

