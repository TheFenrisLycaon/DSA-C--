s = input("")
i = len(s) - 1
v = ['A', 'E', 'I', 'O', 'U', 'Y']
 
while i >= 0:
    if s[i].isalpha():
        u = s[i].upper()
        if u in v:
            print("YES")
        else:
            print("NO")
        break
    else:
        i -= 1