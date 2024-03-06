#https://codeforces.com/problemset/problem/1140/B

rep = int(input())

for i in range(rep):
    a = int(input())
    string = input()

    if(string[0] == "<" and string[-1] == ">"):
        mc = 0
        mf = 0
        for i in range(len(string)):
            if(string[i] == "<"):
                mc += 1
            else:
                break
        for i in range(len(string)-1, -1, -1):
            if(string[i] == ">"):
                mf += 1
            else:
                break
        print(min(mc, mf))

    else:
        print(0)