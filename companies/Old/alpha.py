def findthesum(input1, input2):
    str1 = set(input1)
    str2 = set(input2)
    both = list(str1.symmetric_difference(str2))
    asc = sum(list(map(ord, both)))
    while asc // 10 != 0:
        asc = asc // 10 + asc % 10
    return asc


print(findthesum(list(input()), list(input())))
