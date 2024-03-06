m,n = list(map(int, input().split()))
for i in range(1,m+1):
        if i%2 != 0:
            print(n*'#')
        elif i%4 ==0:
            print('#'+(n-1)*'.')
        else :
            print((n-1)*'.'+'#')
    
        
