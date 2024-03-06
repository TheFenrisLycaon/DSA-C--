def search(L,R,N,A):
    return sum([1 if i in range(L,R+1) else 0 for i in A ])


print(search(20,72,4, [61,20,72,53]))