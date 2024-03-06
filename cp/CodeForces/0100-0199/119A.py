from fractions import gcd
a,b,c = map(int, input().split())
while c != 0:
    i=gcd(a,c)
    c=c-i

if c<i:
    print('0')
else:
    print('1')

