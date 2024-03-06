def snail(snail_map):
    results = []
    while len(snail_map) > 0:
        results += snail_map[0]
        del snail_map[0]
        if len(snail_map) > 0:
            for i in snail_map:
                results += [i[-1]]
                del i[-1]
            if snail_map[-1]:
                results += snail_map[-1][::-1]
                del snail_map[-1]
            for i in reversed(snail_map):
                results += [i[0]]
                del i[0]
    return results


snail_map = [[1, 2, 3], [8, 9, 4], [7, 6, 5]]


print(snail(snail_map))
