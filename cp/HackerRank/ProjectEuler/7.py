def isPrime(x):
    x = int(x)
    for i in range(2, int(x**.5)+1):
        if x % i == 0:
            return False
    return True


n = int(input())
data = {}
data[1] = 2
num = 2
for i in range(1, 10001):
    while(not isPrime(num)):
        num += 1
    data[i] = num
    num += 1
for k in range(n):
    testdata = input()
    i = int(testdata)
    print(data[i])
