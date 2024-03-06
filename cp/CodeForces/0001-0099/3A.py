# Question: https://codeforces.com/problemset/problem/3/A

s=input()
t=input()
l=[]
count=0
while s!=t:
    if s[0]==t[0]:
        if int(s[1])>int(t[1]):
            l.append("D")
            s=s[0]+str(int(s[1])-1)
            count+=1
        elif int(s[1])<int(t[1]):
            l.append("U")
            s=s[0]+str(int(s[1])+1)
            count+=1
    elif s[1]==t[1]:
        if s[0]>t[0]:
            l.append("L")
            s=chr(ord(s[0])-1)+s[1]
            count+=1
        elif s[0]<t[0]:
            l.append("R")
            s=chr(ord(s[0])+1)+s[1]
            count+=1
    elif  s[0]>t[0] and int(s[1])<int(t[1]):
        s=chr(ord(s[0])-1)+s[1]
        s=s[0]+str(int(s[1])+1)
        l.append("LU")
        count+=1
    elif s[0]>t[0] and int(s[1])>int(t[1]):
        s=chr(ord(s[0])-1)+s[1]
        s=s[0]+str(int(s[1])-1)
        l.append("LD")
        count+=1
    elif  s[0]<t[0] and int(s[1])<int(t[1]):
        s=chr(ord(s[0])+1)+s[1]
        s=s[0]+str(int(s[1])+1)
        l.append("RU")
        count+=1
    elif s[0]<t[0] and int(s[1])>int(t[1]):
        s=chr(ord(s[0])+1)+s[1]
        s=s[0]+str(int(s[1])-1)
        l.append("RD")
        count+=1    
        
print(count)
if len(l)!=0:
    print("\n".join(l))

        
