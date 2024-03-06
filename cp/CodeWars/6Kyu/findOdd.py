import collections

def find_it(seq):
    kt = dict(collections.Counter(seq))
    l = {}
    for k, v in kt.items():
        l[v] = k
    for i in l.keys():
        if i%2!=0:
            return l[i]
    return None