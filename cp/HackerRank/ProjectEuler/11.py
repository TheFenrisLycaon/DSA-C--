data = []
for i in range(20):
    data.append(input().split())
ans = 0
for r in range(len(data)):
    i = 0
    while ((i+3) < len(data[0])):
        pdt = int(data[r][i])*int(data[r][i+1]) * \
            int(data[r][i+2])*int(data[r][i+3])
        if pdt > ans:
            ans = pdt
        if (r+3) < len(data):
            pdt = int(data[r][i])*int(data[r+1][i+1]) * \
                int(data[r+2][i+2])*int(data[r+3][i+3])
            if pdt > ans:
                ans = pdt
        if (r-3) > -1:
            pdt = int(data[r][i])*int(data[r-1][i+1]) * \
                int(data[r-2][i+2])*int(data[r-3][i+3])
            if pdt > ans:
                ans = pdt
        i += 1
for c in range(len(data[0])):
    i = 0
    while ((i+3) < len(data)):
        pdt = int(data[i][c])*int(data[i+1][c]) * \
            int(data[i+2][c])*int(data[i+3][c])
        if pdt > ans:
            ans = pdt
        i += 1
print(ans)
