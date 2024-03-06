import math
from functools import reduce

def list_squared(m, n):
    res = []
    for num in range(m, n+1):
        sqListSum = sum([x**2 for x in set(reduce(list.__add__, ([i, num//i]
                        for i in range(1, int(num**0.5) + 1) if num % i == 0)))])
        if int(math.sqrt(sqListSum)) == math.sqrt(sqListSum):
            res.append([num, sqListSum])
    return res