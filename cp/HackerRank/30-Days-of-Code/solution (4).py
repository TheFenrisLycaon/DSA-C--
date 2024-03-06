n = int(input())

if (n % 2 == 1) or (n in range(6, 21)):
    print("Weird")
else:
    print("Not Weird")
