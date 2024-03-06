s = [2, 3, 7, 3, 2, 2]
b = [5, 4, 1, 4, 9, 3]
n = list("abcdef")
q = [3, 5, 1, 2, 6, 4]
d = list(zip(s, b))
data = dict(zip(n, d))
data = dict(
    sorted(data.items(), key=lambda item: (item[1][0], -item[1][1]), reverse=True)
)
final = list(data.items())

for j in q:
    print(final[j - 1][0], end=" ")
