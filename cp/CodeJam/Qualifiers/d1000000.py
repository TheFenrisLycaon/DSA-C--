"""Question 3 for CodeJam"""


def choose_dice(num: int, dices: list) -> int:
    """Returns number of dice"""
    max_dice = max(dices)
    data = [0] * (max_dice + 1)

    for i in range(num):
        data[dices[i]] += 1

    res = 0
    curr = 0

    for i in range(max_dice, 0, -1):
        curr += data[i]
        if curr > 0:
            curr -= 1
            res += 1

    return res


def main() -> int:
    """Main function"""
    return choose_dice(int(input()), list(map(int, input().split())))


if __name__ == "__main__":
    for case in range(int(input().strip())):
        print(f"Case #{case + 1}:{main()}")
