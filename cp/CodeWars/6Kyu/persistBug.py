from functools import reduce

def persistence(n):
    count = 0
    while n > 9:
        n = reduce(lambda x, y: int(x)*int(y), str(n))
        count += 1
    return count