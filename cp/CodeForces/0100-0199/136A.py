n = int(input())
l = list(map(int, input().split()))
a = []
for i in range (n):
    a.append(l.index(i+1)+1)    
print(" ".join(map(str, a)))





