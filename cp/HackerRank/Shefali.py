ALPHA = {
    "a": 1,
    "b": 1,
    "c": 2,
    "d": 2,
    "e": 2,
    "f": 3,
    "g": 3,
    "h": 3,
    "i": 4,
    "j": 4,
    "k": 4,
    "l": 5,
    "m": 5,
    "n": 5,
    "o": 6,
    "p": 6,
    "q": 6,
    "r": 7,
    "s": 7,
    "t": 7,
    "u": 8,
    "v": 8,
    "w": 8,
    "x": 9,
    "y": 9,
    "z": 9,
}


def solve(s: str) -> int:
    return len(
        [
            x
            for x in [s[i : j + 1] for i in range(len(s)) for j in range(i, len(s))]
            if sum([ALPHA[i] for i in x]) % len(x) == 0
        ]
    )


def get_subs(s: str) -> list[str]:
    return [s[i : j + 1] for i in range(len(s)) for j in range(i, len(s))]


def ext_subs(s: str) -> int:
    count = 0
    for x in get_subs(s):
        score = sum([ALPHA[i] for i in x])
        if score % len(x) == 0:
            count += 1
    return count


print(ext_subs("asdf"))
print(solve("asdf"))
