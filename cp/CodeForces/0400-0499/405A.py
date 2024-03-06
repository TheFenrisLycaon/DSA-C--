n = int(input())
l = list(map(int, input().strip().split()))
l.sort()
print (" ".join([str(x) for x in l]) )


