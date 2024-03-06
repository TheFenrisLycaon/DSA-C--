def order_weight(strng):
    weights = strng.split()

    def sumD(number):
        return sum([int(d) for d in str(number)])

    weights.sort()
    weights.sort(key=sumD)

    return ' '.join(weights)