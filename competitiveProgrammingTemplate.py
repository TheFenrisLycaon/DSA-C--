import sys
import time
# using template by FenrisLycaon

def maxSequence(arr):
    max,curr=0,0
    for x in arr:
        curr+=x
        if curr<0:curr=0
        if curr>max:max=curr
    return max

def getIn(x):
    # custom input
    # supposed to be faster
    if x == 'ints':
        return list(map(int, sys.stdin.readline().strip().split()))
    elif x == 'int':
        return int(sys.stdin.readline().strip().split()[0])
    elif x == 'float':
        return float(map(float, sys.stdin.readline().strip().split()))
    elif x == 'list':
        return list(map(sys.stdin.readline().strip().split()))
    elif x == 'str':
        return str(sys.stdin.readline().strip())
    elif x == 'charlist':
        return list(map(str, input().strip().split()))
    else:
        print("Input not recognised.")
        return 0

def goOut(x):
    # custom output
    # supposed to be faster
    if type(x) is list:
        for _ in x:
            goOut(_)            
        # sys.stdout.flush() 
    else:
        sys.stdout.write(str(x)+'\n')
        # sys.stdout.flush() 

if __name__ == "__main__":
    startingTime = time.time()
    res = []

    # code here


    # output ahead
    goOut(res)

    # to check performance uncomment the next line
    # goOut(time.time()-startingTime)
