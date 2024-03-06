s = input("")

def chk(s, idx):
    for i in range(idx, len(s)):
        if (s[i].islower()):
            return 0
    return 1

if chk(s, 0):
    ns = s.lower()
elif chk(s, 1):
    ns = s[0].upper() + s[1:].lower()
else:
    ns = s

print(ns)