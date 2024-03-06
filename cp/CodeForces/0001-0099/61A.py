a = input()
b = input()
l = []
for i in range(len(a)):
    if a[i] == b[i]:
        l.append("0")
    else:
        l.append("1")
print ("".join(l))        
