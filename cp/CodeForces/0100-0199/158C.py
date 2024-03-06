n = int(input())

cur = []

def pwd(cur):
    if len(cur) == 0:
        print('/')
    else:
        print('/' + '/'.join(cur) + '/')

def process(cmd, cur):
    cmd = cmd[3:]
    ds = cmd.split('/')    
    if cmd[0] == '/':
        cur = []
    for d in ds:
        if d == '..':
            cur.pop()
        elif len(d) > 0:
            cur.append(d)
    return cur
        
while n > 0:
    n -= 1
    c = input()
    if c == 'pwd':
        pwd(cur)
    else:
        cur = process(c, cur)