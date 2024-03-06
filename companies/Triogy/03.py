import itertools

def solve(A,B):
    C = [i | j for i,j in itertools.product(A,B)]
    print(list(C))


solve([2], [5,0,3])