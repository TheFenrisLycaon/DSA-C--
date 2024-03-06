n = int(input())
for i in range (n):
    l = input()
    if len(l) < 10:
        print (l)
    elif len(l) >= 10:
            print (l[0] + str(len(l)-2) + l[len(l)-1])
