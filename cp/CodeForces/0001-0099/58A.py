a = list(input())
print (a)
i = 0
for i in range(len(a)-1):
    if a[i] == a[i+1]:
        a[i+1] = '1'
print (a)        
s=''.join(a).split('1')
print(s)

        
        
