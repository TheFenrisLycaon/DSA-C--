from math import factorial as f

for i in range(int(input())):
    st = str(f(int(input())))
    s = 0
    for i in range(len(st)):
        s += int(st[i])
    print(s)
