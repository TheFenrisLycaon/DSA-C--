for i in range(int(input())):
    pdt = 0
    N, K = input().split()
    K_int = int(K)
    N_int = int(N)
    Num = input()
    for p in range(N_int-K_int):
        val = 1
        for w in range(K_int):
            val *= int(Num[p+w])
        if val > pdt:
            pdt = val
    print(pdt)
