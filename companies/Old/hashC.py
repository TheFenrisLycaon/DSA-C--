import itertools

filne = "./a_an_example.in.txt"

with open(filne, "r+") as f:
    lines = iter([x.strip().split() for x in f.readlines()])
    try:
        n, m = map(int, next(lines))
        # print(n, m)

        names = {}

        for i in range(n):
            name, *_ = next(lines)
            names[name] = i
    except Exception as e:
        pass
