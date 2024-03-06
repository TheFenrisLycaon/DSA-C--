#Question: https://codeforces.com/problemset/problem/144/A

n = int(input())
l = list(map(int,input().split()))
#p = l.index(max(l))
#q = l.index(min(l))
small = 100
count = 0
large = 0
sum = 0
for i in range (n):
    if l[i] == min(l):
        p = i
        if p > large:
            large = p
    
#print (large)

for i in range(large,n-1,+1):
    l[i],l[i+1] = l[i+1],l[i]
    sum = sum+1
    if l[n-1] == min(l):
        break
#print (sum)


for i in range(n):
    if l[i] == max(l) :
        q = i
        if q < small:
            small = q

#print (small)

for i in range(small,0,-1):
    l[i],l[i-1] = l[i-1],l[i]
    count = count+1
    if l[0] == max(l):
        break
#print (count)

print (count+sum)


