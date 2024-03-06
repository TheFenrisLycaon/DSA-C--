def reverse_list(L):
    for i in range(len(L) // 2):
        L[i], L[-(i+1)] = L[-(i+1)], L[i]


def main():
    _ = int(input())
    input_list = [int(x) for x in input().split()]
    reverse_list(input_list)
    print(*input_list)


if __name__ == "__main__":
    main()


# or just simply print(*reversed(input().split()))
