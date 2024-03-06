def max_sequence(a):
    # ... 
    size = len(a)
    maxFar = 0
    maxCurr = 0
      
    for i in range(0, size):
        maxCurr = maxCurr + a[i]
        if (maxFar < maxCurr):
            maxFar = maxCurr
 
        if maxCurr < 0:
            maxCurr = 0  
    
    return maxFar