from math import ceil

names = ['Sheldon', 'Leonard', 'Penny', 'Rajesh', 'Howard']

n = int(input())

i = 0
j = 1
k = len(names)

while i <= n:
    i += k
    k += k    
    j += j

print(names[int(ceil((n - (i - k * 0.5)) / (j * 0.5)) - 1)])