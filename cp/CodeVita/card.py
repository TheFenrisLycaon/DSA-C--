def match(cards, availItems):
    res = []
    for card in cards:
        for item in card:
            if item in availItems:
                res.append(item)
    return res


def mismatch(cards, x):
    res = []
    availItems = x
    for card in cards:
        for item in card:
            for property in item.split(" "):
                for available in availItems:
                    if property in available:
                        availItems.remove(available)
                        break
                    else:
                        res.append(available)
                        break

    return set(res)


if __name__ == "__main__":
    avail = int(input())
    prop = int(input())
    availItems = [input().strip() for _ in range(avail)]
    cardsNum = int(input())
    cards = [[input().strip(), input().strip()] for _ in range(cardsNum)]
    print()
    print("\n".join(match(cards, availItems)))
    print("\n".join(mismatch(cards, availItems)))
