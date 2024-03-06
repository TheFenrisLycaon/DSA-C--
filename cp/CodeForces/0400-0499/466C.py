#https://codeforces.com/problemset/problem/466/C

def calc():
    a = int(eval(input()))
    lista = list(map(int, input().split()))
    soma = sum(lista)
    resus = [0 for i in range(a+10)]
    if(soma%3 == 0 and a >= 3):
        soma /= 3
        ss = 0
        for i in range(a-1, 0, -1):
            ss += lista[i]
            if(ss == soma):
                resus[i] = 1
        for i in range(a-2, 0, -1):
            resus[i] += resus[i+1]
 
        cont = 0
        ss = 0
        for i in range(a):
            ss += lista[i]
            if(ss == soma):
                cont += resus[i+2]
        
        
 
        return cont
            
    return 0
 
print((calc()))