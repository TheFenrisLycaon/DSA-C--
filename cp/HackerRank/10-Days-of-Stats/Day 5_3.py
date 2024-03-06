import math
mean=20.0
stddev=2.0
h1=19.5
h21,h22=20.0,22.0

def integrate(func,b,n=10000):
    step=1/n
    if(b<0):step=-step
    n=int(abs(b)*n)
    a=0.0
    sq=0.0
    for _ in range(0,n):
        sq+=step*func(a)
        a+=step
    return abs(sq)

erf = lambda b : (2*math.pi**(-0.5)) * integrate(lambda x: math.exp(-x**2),b)
phi = lambda b : (1 + erf( (b-mean) / (stddev * 2**0.5) ))/2
lesh1 = phi(0.0) - phi(h1)
beth1h2 = phi(h22) - phi(h21)
print(f'{lesh1:.3f}')
print(f'{beth1h2:.3f}')
