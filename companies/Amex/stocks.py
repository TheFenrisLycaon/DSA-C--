class Sol:
    def func(self, x, y):
        res = [y[0]]
        for idx, val in enumerate(y[1:]):
            res.append(res[idx] + val)
        return min(res)


print(Sol().func(5, [-1, -2, 3, 0, 1]))
