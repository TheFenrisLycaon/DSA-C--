#Question: https://codeforces.com/problemset/problem/110/A 

n = input()
count = 0
for i in range(len(n)):
    if (n[i]) == '4' or (n[i]) == '7':
        count = count+1       
if count == 7 or count == 4  :
    print("YES")
else:
    print("NO")
