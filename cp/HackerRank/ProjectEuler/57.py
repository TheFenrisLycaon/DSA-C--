import math
from fractions import Fraction
from decimal import Decimal
N=int(input())
old=Fraction(3, 2)
for i in range(N-1):
    old-=1
    new=1+ (1/(2+old))
    nr,dr=str(new).split('/')
    if len(nr)>len(dr):
        print(i+2)
    old=new
