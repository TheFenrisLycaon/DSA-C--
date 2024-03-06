v = ['a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y']
s = input()

r = ''
for i in s:
    if any(i in y for y in v):
        pass
    else:
        r += '.'  + i.lower()

print(r)