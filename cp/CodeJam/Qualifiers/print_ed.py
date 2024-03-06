"""Question 2 for CodeJam"""

NEEDED_INK = 10**6


def main():
    """Main Function"""
    min_ink = [NEEDED_INK] * 4

    for _ in range(3):
        printers = list(map(int, input().split()))
        for color in range(4):
            min_ink[color] = min(printers[color], min_ink[color])

    if sum(min_ink) < NEEDED_INK:
        return "IMPOSSIBLE"

    need = NEEDED_INK

    for color in range(4):
        if min_ink[color] <= need:
            need -= min_ink[color]

        else:
            min_ink[color] = need
            need = 0

    return " ".join(map(str, min_ink))


if __name__ == "__main__":
    for case in range(int(input().strip())):
        print(f"Case #{case + 1}: {main()}")
