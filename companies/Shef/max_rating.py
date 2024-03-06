def max_rating(arr):
    return list(reversed(sorted(arr)[-2:]))

print(max_rating([200,-500,450,125, -50]))