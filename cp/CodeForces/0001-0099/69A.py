
n = int(input())

sx = 0
sy = 0
sz = 0

for i in range(0, n):
    ss = input().split(" ")
    sx += int(ss[0])
    sy += int(ss[1])
    sz += int(ss[2])

print("YES" if sx == 0 and sy == 0 and sz == 0 else "NO")
    
