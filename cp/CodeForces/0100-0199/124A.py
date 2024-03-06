
s = input().split(" ")
n = int(s[0])
a = int(s[1])
b = int(s[2])

print(b + 1 if a + b < n else n - a)
