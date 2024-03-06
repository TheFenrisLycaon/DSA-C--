def hashIt(word):
    return sum(ord(i) for i in word)


def vocabHash(d):
    dic = {}

    for i in d:
        if i[0] in dic:
            dic[i[0]].append(i[1])
        else:
            dic[i[0]] = [i[1]]

    return dic


def getIn(path):
    with open(path, "r") as f:
        txt = f.readlines()

    return list(map(lambda x: x.strip(), txt[1:]))


def getOut(l1, l2):
    with open("out.txt", "a") as f:
        for i in l1:
            for j in l2:
                f.writelines(" ".join([i, j, "\n"]))


hashedVocab = vocabHash([(hashIt(i), i.strip()) for i in getIn("v.txt")])
hashedInp = list(map(lambda x: hashIt(x), getIn("in.txt")))
for i in hashedInp:
    for j in hashedVocab.keys():
        if i - j in hashedVocab.keys():
            getOut(hashedVocab[j], hashedVocab[i - j])
    with open("out.txt", "a") as f:
        f.writelines("-1\n")
