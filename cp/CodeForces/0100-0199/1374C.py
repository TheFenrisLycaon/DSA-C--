def solve(n, brackets):

    balance_counter = 0
    total_moves = 0

    for i in xrange(0, n):

        balance_counter += 1 if brackets[i] == '(' else -1

        if balance_counter < 0:
            total_moves += 1
            balance_counter = 0

    return total_moves


if __name__ == "__main__":

    t = int(raw_input())

    results = list()
    for _ in xrange(0, t):
        n = int(raw_input())
        brackets = raw_input()
        results.append(solve(n, brackets))

    for result in results:
        print result
