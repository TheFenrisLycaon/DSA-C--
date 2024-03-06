def shift(xl):
    k = xl[0]
    xl.pop(0)
    xl.append(k)
    tx = ''.join(map(str, xl))
    return tx

def highestPower(str, lenngth): 
    ans = 0
    for i in range(lenngth-1,-1,-1): 
        if (str[i] == '0'): 
            ans+=1
        else: 
            break
    return ans 


if __name__ == "__main__":

    x = list(input())
    # print(x)
    y = list(reversed(x))
    # print(y)
    tx = ''.join(map(str, x))
    while x[-1] == '1' or x[0] == '0':
        tx = shift(x)
        if tx == ''.join(map(str, list(reversed(y)))):
            break
        else:
            pass
    
    print(highestPower(tx,len(tx)))