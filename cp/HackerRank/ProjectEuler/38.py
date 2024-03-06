def is_pandigital(nn, K):
    if len(str(nn)) == K:
        for i in range(1, K+1):
            if str(nn).find(str(i)) < 0:
                return False
        return True
    else:
        return False


def uniq_digit(n):
    uniq = sorted(set(str(n)))
    if len(uniq) == len(str(n)):
        return True
    else:
        return False


N, K = input().split()
N = int(N)
K = int(K)
for i in range(2, N):
    m = 2
    mul = str(i)
    while(len(mul) < K):
        if not uniq_digit(i):
            break
        mul += str(i*m)
        m += 1
    if is_pandigital(mul, K):
        print(i)
