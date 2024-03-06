#https://codeforces.com/problemset/problem/577/C

def gerap(MAX):
    MAX += 1
    resposta = []
    primos = [True] * MAX
    primos[0] = False
    primos[1] = False
    for i in range(2, MAX, 1):
        if primos[i]:
            elevado = 1
            while(elevado*i < MAX):
                elevado *= i
                resposta.append(str(elevado))
            for j in range(i*2, MAX, i):
                primos[j] = False
    return resposta
 
a = int(eval(input()))
primos = gerap(a)
print((len(primos)))
print((" ".join(primos)))