a = input()
b = list(set(a))
c=[]
for i in range(len(b)):
    if b[i].isalpha()==True:
        c.append(b[i])
print(len(c))

