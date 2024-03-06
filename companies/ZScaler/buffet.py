def buffet(aSize,kSize,A,K):
    return sum([1 if j >= K[i] else 0 for j in A for i in range(kSize)])

print(buffet(3,1,[25,35,45], [30]))
print(buffet(3,1,[28,32,63], [48]))