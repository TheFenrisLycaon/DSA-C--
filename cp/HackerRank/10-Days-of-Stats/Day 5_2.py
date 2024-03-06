X, Y = [float(num) for num in input().split(" ")]
Cx = 160 + 40*(X +X**2)
Cy = 128 + 40*(Y + Y**2)
print(round(Cx, 3))
print(round(Cy, 3))
