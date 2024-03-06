n = int(input())
l = list(input())
A = l.count('A')
B = l.count('D')

if A>B:
    print("Anton")
elif B>A:
    print("Danik")
else :
    print("Friendship")
