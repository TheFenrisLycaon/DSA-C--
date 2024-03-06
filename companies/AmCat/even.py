def even_subsequences(Arr):
    for i in range(len(Arr)):
        for j in range(i + 2, len(Arr) + 1, 2):
            if sum(Arr[i:j]) != 0:
                return "NO"
    return "YES"


print(even_subsequences([8, -8, 7, 9]))
print(even_subsequences([0, 0]))
print(even_subsequences([6,-6,-10,2,2,2,4,-5]))
