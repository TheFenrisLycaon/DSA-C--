def rot13(message):
    alphaL = 'abcdefghijklmnopqrstuvwxyz'
    alphaU = 'abcdefghijklmnopqrstuvwxyz'.upper()
    res = ''
    for x in message:
        if x.islower():
            i = alphaL.index(x) + 13
            if i >= 26:
                i -= 26
            res += alphaL[i]
        elif x.isupper():
            i = alphaU.index(x) + 13
            if i >= 26:
                i -= 26
            res += alphaU[i]
        else:
            res+=x
    return res