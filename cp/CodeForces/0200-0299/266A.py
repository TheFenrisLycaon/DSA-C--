n = input()
a = input().strip()
l=[]
for i in range(len(a)):
    l.append(a[i])
print(l)
count = 0 
for i in range (len(a)-1):
    if (a[i] == a[i+1]):
        count = count + 1
print (count)
     

