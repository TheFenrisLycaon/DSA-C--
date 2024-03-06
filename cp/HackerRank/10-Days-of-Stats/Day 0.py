n = int(input())
x = [int(i) for i in input().split()]

x.sort()

def freq(lst):
    dict = {}
    for n in lst:
        keys = dict.keys()
        if n in keys:
            dict[n] += 1
        else:
            dict[n] = 1
    return dict


mean = sum(x)/n
print(round(mean,1))

median = (x[n//2]+x[(n//2)-1])/2
print(round(median,1))

t = freq(x)
mode = max(t, key=t.get) 
print(mode) 
