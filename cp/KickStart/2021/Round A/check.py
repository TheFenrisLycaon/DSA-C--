#  bitwise xor = ^

for _ in range(int(input())):
    x = int(input())
    matA = []
    matB = []
    checkR = []
    checkC = []
    for i in range(x):
        matA.append(list(map(int, input().split())))
        matB.append(list(map(int, input().split())))
        checkR.append(list(map(int, input().split())))
        checkC.append(list(map(int, input().split())))
    
    