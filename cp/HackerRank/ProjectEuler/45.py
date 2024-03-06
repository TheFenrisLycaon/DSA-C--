import math


def solve_quadratic(a, b, c):
    d = math.sqrt((b**2)-(4*a*c))
    x1 = (-b+d)/(2*a)
    x2 = (-b-d)/(2*a)
    return(x1, x2)


def get_range(val):
    N = int(val[0])
    val.remove(val[0])
    t_end = 0
    p_end = 0
    h_end = 0
    for x in val:
        if x == '3':
            x1, x2 = solve_quadratic(1, 1, -2*N)
            t_end = int(max(x1, x2))
        elif x == '5':
            x1, x2 = solve_quadratic(3, -1, -2*N)
            p_end = int(max(x1, x2))
        elif x == '6':
            x1, x2 = solve_quadratic(2, -1, -N)
            h_end = int(max(x1, x2))
    return(t_end, p_end, h_end)


val = input().split()
arr = []
common = {}
key = val[1]+val[2]
common['35'] = [1, 210, 40755, 7906276,
                1533776805, 297544793910, 57722156241751]
common['56'] = [1, 40755, 1533776805, 57722156241751]
common['53'] = common['35']
common['65'] = common['56']
for x in common[key]:
    if x < int(val[0]):
        print(x)
    else:
        break
