"""Question 1 for CodeJam"""


def row_generator(length: int, wall: bool = True) -> str:
    """Generates a row of a card"""
    return (
        "|" + "|".join(["."] * (length)) + "|"
        if wall
        else "." + "|".join(["."] * (length)) + "|"
    )


def boundary_generator(length: int, wall: bool = True) -> str:
    """Generates a boundary of a card"""
    return "-".join(["+"] * (length + 1)) if wall else ".." + "-".join(["+"] * (length))


def main():
    """Main Function"""
    rows, columns = map(int, input().strip().split())
    card = [boundary_generator(columns, 0)] + [
        row_generator(columns, idx) + "\n" + boundary_generator(columns)
        for idx in range(rows)
    ]
    return "\n".join(card)


if __name__ == "__main__":
    for case in range(int(input().strip())):
        print(f"Case #{case + 1}:\n{main()}")
