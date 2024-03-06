def loop_size(node):
    l = []
    i = 0
    while True:
        if node in l:
            return i - l.index(node)
        else:
            l.append(node)
            i+=1
     