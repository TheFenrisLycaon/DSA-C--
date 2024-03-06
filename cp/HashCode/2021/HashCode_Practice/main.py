import os
from random import shuffle

files = os.listdir('inputFiles/')

l = len(files)

for i in range(l):
    files[i] = files[i][:-3]


def solve(m, x2, x3, x4, ing, x):
   
    i, score = 0, 0
    shuffle(x)
    num2, num3, num4 = [], [], []
   
    while i < m:
   
        if i+2 <= m and x2 > 0:
   
            x2 -= 2
            num2.append([x[i], x[i+1]])
            ss = len(set(ing[x[i]]+ing[x[i+1]]))
            i += 2
   
        elif i+3 <= m and x3 > 0:
   
            x3 -= 3
            num3.append([x[i], x[i+1], x[i+2]])
            ss = len(set(ing[x[i]]+ing[x[i+1]]+ing[x[i+2]]))
            i += 3
   
        elif i+4 <= m and x4 > 0:
   
            x4 -= 4
            num4.append([x[i], x[i+1], x[i+2], x[i+3]])
            ss = len(set(ing[x[i]]+ing[x[i+1]]+ing[x[i+2]]+ing[x[i+3]]))
            i += 4
   
        else:
   
            break
   
        score += ss**2
   
    return len(num2), len(num3), len(num4), num2, num3, num4, score


for i in range(l):
    
    with open('inputFiles/'+files[i]+'.in', 'r') as f:

        content = f.readlines()
        ingredients = []
    
        m, t2, t3, t4 = [int(x) for x in content[0].split()]
    
        for j in range(1, m+1):
            ingredient = content[j].split()[1:]
            ingredients.append((ingredient))
    
    bestScore = 0
    bestTwo, bestThree, bestFour = [], [], []
    vals = list(range(m))
    
    for _ in range(10000):

        l2, l3, l4, two, three, four, score = solve(
            m, 2*t2, 3*t3, 4*t4, ingredients, vals)

        if score > bestScore:
            bestScore, bestTwo, bestThree, bestFour = score, two, three, four
    
    with open('outputFiles/'+files[i]+'.out', 'w') as f:
    
        f.write(str(l2+l3+l4)+'\n')
    
        for ii in range(l2):
    
            f.write('2 ')
    
            for j in range(2):
                f.write(str(bestTwo[ii][j])+' ')
    
            f.write('\n')
    
        for ii in range(l3):
    
            f.write('3 ')
    
            for j in range(3):
                f.write(str(bestThree[ii][j])+' ')
    
            f.write('\n')
    
        for ii in range(l4):

            f.write('4 ')

            for j in range(4):
                f.write(str(bestFour[ii][j])+' ')

            f.write('\n')

    print("Done ", files[i], "\nScore :", bestScore)

print("All Done")
