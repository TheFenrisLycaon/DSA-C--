def solve(n):

    space_deliminator = " "
    for row in xrange(-n, n+1):
        max_value = n - abs(row)
        this_line = ""
        # add the spaces
        for i in xrange(0, abs(row)):
            this_line += (2 * space_deliminator)
        # incremental loop
        for i in xrange(0, max_value):
            this_line += str(i) + space_deliminator
        # decremental loop
        for i in xrange(max_value, -1, -1):
            this_line += str(i) + space_deliminator
        # remove that one extra space after the last 0
        print this_line[:-1]


if __name__ == "__main__":
    n = int(raw_input())
    solve(n)