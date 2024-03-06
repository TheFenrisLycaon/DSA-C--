def find_outlier(integers):
    ec = 0
    oc = 0
    for i in integers[:4]:
        if i%2 == 0:
            ec += 1
        else:
            oc += 1
    
    if oc >= 2:
        for i in integers :
            if i%2 == 0:
                return i
    elif ec >= 2:
        for i in integers:
            if i%2 != 0:
                return i
        