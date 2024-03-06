def output(List):
    return "".join(List)


def permute(inp, length=0):
    string = list(inp)
    ran = len(string)
    if length == ran:
        print(output(string))
    else:
        for i in range(length, ran + 1):
            string[length], string[i] = string[i], string[length]
            permute(string, length + 1, ran)
            string[length], string[i] = string[i], string[length]


if __name__ == "__main__":
    permute(input())
