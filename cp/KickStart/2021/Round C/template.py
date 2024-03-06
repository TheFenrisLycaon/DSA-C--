from collections import deque, Counter
import sys
import time
# using template by FenrisLycaon


def getIn(x):
    # custom input
    # supposed to be faster
    if x == 'ints':
        return list(map(int, sys.stdin.readline().strip().split()))
    elif x == 'int':
        return int(sys.stdin.readline().strip().split()[0])
    elif x == 'float':
        return float(map(float, sys.stdin.readline().strip().split()))
    elif x == 'list':
        return list(map(sys.stdin.readline().strip().split()))
    elif x == 'str':
        return str(sys.stdin.readline().strip())
    elif x == 'charlist':
        return list(map(str, input().strip().split()))
    else:
        print("Input not recognised.")
        return 0


def goOut(x):
    # custom output
    # supposed to be faster
    if type(x) is list:
        for _ in x:
            goOut(_)
        # sys.stdout.flush()
    else:
        sys.stdout.write(str(x)+'\n')
        # sys.stdout.flush()


def palindrome_from(letters):
    counter = Counter(letters)
    sides = []
    center = deque()
    for letter, occurrences in counter.items():
        repetitions, odd_count = divmod(occurrences, 2)
        if not odd_count:
            sides.append(letter * repetitions)
            continue
        if center:
            raise ValueError("no palindrome exists for '{}'".format(letters))
        center.append(letter * occurrences)
    center.extendleft(sides)
    center.extend(sides)
    return ''.join(center)


def summ(x):
    my_sum = 0
    i = 0
    #replace this pass (a do-nothing) statement with your code
    while i <= x:
        my_sum = my_sum + i
        i += 1
    return my_sum

if __name__ == "__main__":
    # startingTime = time.time()
    res = []

    """ code here """

    print(summ(3))




    goOut(res)

    # to check performance uncomment the next line
    # goOut(time.time()-startingTime)
