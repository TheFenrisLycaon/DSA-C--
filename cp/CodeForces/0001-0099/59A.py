a = input()
b=[]
c=[]
for i in range(len(a)):
    if a[i].isupper():
        b.append(a[i])
    else:
        c.append(a[i])
if len(b)>len(c):
    print(a.upper())
else :
    print(a.lower())
        
# instead of taking two arrays, using a counter
string = input()
c = 0
for i in range(0, len(string)):
    if string[i] == string[i].upper() :
        c = c+1
    else:
        c = c-1
if c>0:
    print(string.upper())
else:
    print(string.lower())

