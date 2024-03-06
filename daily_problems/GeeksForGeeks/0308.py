def reverse(S: str) -> str:
    stack = []
    for i in S:
        stack.append(i)
    res = ""
    for i in range(len(stack)):
        res += stack.pop()

    return res


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        str1 = input()
        print(reverse(str1))
