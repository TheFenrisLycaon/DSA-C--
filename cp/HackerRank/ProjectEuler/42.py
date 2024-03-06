import math

for x in range(int(input())):
    testdata = input()
    ans = -1
    x_int = int(testdata)*2
    a = math.floor(math.sqrt(x_int))
    if a*(a+1) == x_int:
        ans = a
    print(ans)