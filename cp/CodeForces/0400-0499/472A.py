n = int(input())
if n > 9:
    print (9,n-9)
else:
    while i < n:
        if i + n-i == n and n % i != 0 :
            print (i,n-i)
            break
        i = i+1
    #print(a-1,n-a+1)
