import bisect

def Smallestonleft (arr,  n) : 
    res = []
    listo =[] 
    
    for item in arr:
        bisect.insort(listo,item)
        j = bisect.bisect_left(listo,item)
        if j==0:
           res.append(-1)
        else:
            res.append(listo[j-1])
        
    return res



#{ 
#  Driver Code Starts
#Initial Template for Python 3


for _ in range(0,int(input())):
    
    n = int(input())
    arr = list(map(int,input().strip().split()))
    res = Smallestonleft(arr, n);
    for each in res:
        print(each,end=' ')
    print()




# } Driver Code Ends