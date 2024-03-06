def rgb(r, g, b):
    res = ''
    for i in [r,g,b]:
#         print(i)
        h = hex(i).split('x')[-1]
        try:
            res += "{:02}".format(int(h))*(i<255 and i > 0) + 'FF'*(i>255) + '00'*(i<=0)
#             print()
        except:
            res+= '0'*(len(h)<2) + h.upper()*(i<255 and i > 0) + 'FF'*(i>=255) + '00'*(i<=0)
#             print(res)

        
    return ''.join(res)