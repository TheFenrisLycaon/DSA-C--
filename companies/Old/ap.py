import collections


def check_duplicates(x):
    k = dict(collections.Counter(x))
    if sum(k.values()) == len(k.values()):
        return False
    else:
        return True


def smoolNum(N):
    k = (N % 9 + 1) * pow(10, (N // 9)) - 1
    if check_duplicates(list(str(k))):
        return -1
    else:
        return k


res = []
for _ in range(int(input())):
    n = int(input())
    res.append(smoolNum(n))

for i in res:
    print(i)
