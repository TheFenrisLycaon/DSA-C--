n = int(input())
a = list(map(int, input().split()))

k = [sum(a[i : : 2]) for i in range(len(a)//(len(a)//2))]

print(2*min(k))
# print(even,odd, sep='\n')


