# Question: https://codeforces.com/problemset/problem/451/A

a,b = list(map(int, input().split()))
if a>b:
    if b%2==0:
        print("Malvika")
    else:
        print ("Akshat")
        
else:
    if a%2==0:
        print("Malvika")
    else:
        print ("Akshat")
