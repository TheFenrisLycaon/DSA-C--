def stackDisplay(N, arr):
    stack = []
    ret = []
    for c in arr:
        if c == 0:
            try:
                stack = stack[:-1]
            except:
                ret.append(0)
                continue
        else:
            stack.append(c)

        ret.append(sum([i * j**2 for i in stack for j in stack]))

    return ret


print(stackDisplay(7, [1, 4, -5, 0, 0, 0, 0]))
print(stackDisplay(3, [5, 0, 0]))
