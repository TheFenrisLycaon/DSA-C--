def maxima(N, A):
    e = [i for i in A if i%2 ==0]
    o = [i for i in A if i%2!= 0]
    return max(e) - min(e) + max(o) - min(o)

print(maxima(7,  [1,3,6,8,2,6,8]))