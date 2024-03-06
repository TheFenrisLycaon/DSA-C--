n = int(input())
x = [int(i) for i in input().split()]
w = [int(i) for i in input().split()]
t=[]

for i in range(n):
    t.append(x[i]*w[i])

mean = sum(t)/sum(w)
print(round(mean,1))
