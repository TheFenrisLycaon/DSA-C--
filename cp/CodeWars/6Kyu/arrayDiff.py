def array_diff(a, b):
    for i in b:
        a = [x for x in a if x != i ]
    return a