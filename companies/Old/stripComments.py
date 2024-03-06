def solution(string, markers):
    st = string.split("\n")
    res = []

    for line in st:
        for pointer in range(len(line)):
            if line[pointer] in markers:
                line = line[:pointer]
                break

        res.append(line)

    string = "\n".join(res)
    return string


print(solution("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"]))
print(solution("a #b\nc\nd $e f g", ["#", "$"]))
