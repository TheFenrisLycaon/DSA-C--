from math import factorial as f

for i in range(int(input())):
    t = input()
    n = int(t)-1
    char = "abcdefghijklm"
    char_ar = sorted(char)
    out = ''
    for c in range(len(char_ar)-1, -1, -1):
        p = int(n/f(c))
        out += char[p]
        if len(char) > 0:
            char = char[:p]+char[p+1:]
        n = n % f(c)
    print(out)
