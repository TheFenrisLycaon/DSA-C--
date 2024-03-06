class UserMainCode(object):
    def pangram(cls, input1, input2, input3):
        res = input1 + 1
        for i in reversed([
            input2[i : i + j]
            for i in range(0, len(input2))
            for j in range(1, len(input2) - i + 1)
        ]):
            score = len(set("".join(i)))
            if score == 26:
                res = min(len(i), res)
        return res if res <= input1 else -1


se = UserMainCode()
x = se.pangram(
    14,
    [
        "ab",
        "cd",
        "ef",
        "gh",
        "ij",
        "kl",
        "abcd",
        "mn",
        "op",
        "qr",
        "st",
        "uv",
        "wx",
        "yz",
    ],
    [2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2],
)

y = se.pangram(
    9,
    [
        "the",
        "quick",
        "brown",
        "fox",
        "jumps",
        "over",
        "a",
        "lazy",
        "dog",
    ],
    [3, 5, 5, 3, 5, 4, 1, 4, 3],
)


print(x)
print(y)
