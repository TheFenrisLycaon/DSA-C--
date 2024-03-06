from math import sqrt

s = int(input())
mean = int(input())
std = int(input())
interval = float(input())
z = float(input())
print(round(mean - (std / sqrt(s)) * z, 2))
print(round(mean + (std / sqrt(s)) * z, 2))