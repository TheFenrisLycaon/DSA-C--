import numpy as np

m, n = map(int, input().split())
list_of_lists = [list(map(float, input().split())) for _ in range(n)] 
X = np.empty((n, m+2)) 
X[:, 0] = 1 
X[:, 1:] = list_of_lists 
y = X[:, -1] 
X = X[:, :-1]
B = np.dot(np.linalg.inv(np.dot(X.T, X)), np.dot(X.T, y))
q = int(input())
X = np.empty((q, m+1))
X[:, 0] = 1
list_of_lists = [list(map(float, input().split())) for _ in range(q)]
X[:, 1:] = list_of_lists
print('\n'.join(map(str, np.round((X,@B), 2))))