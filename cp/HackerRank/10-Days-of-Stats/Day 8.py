l = [map(int, input().split()) for _ in range(5)]
sx, sy, sz, xy = map(sum, zip(*[(x, y, x**2, x * y) for x, y in l]))
b = (5 * xy - sx * sy) / (5 * sz - sx**2)
a = (sy / 5) - b * (sx / 5)
print('{:.3f}'.format(a + b * 80))
