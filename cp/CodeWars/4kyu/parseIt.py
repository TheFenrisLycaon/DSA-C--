words = {w: n for n, w in enumerate(
    'zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen'.split())}
words.update({w: 10 * n for n, w in enumerate(
    'twenty thirty forty fifty sixty seventy eighty ninety hundred'.split(), 2)})
thousands = {w: 1000 ** n for n, w in enumerate(
    'thousand million billion trillion quadrillion quintillion sextillion septillion octillion nonillion decillion'.split(), 1)}


def parse_int(strng):
    num = group = 0
    for w in strng.replace(' and ', ' ').replace('-', ' ').split():
        if w == 'hundred':
            group *= words[w]
        elif w in words:
            group += words[w]
        else:
            num += group * thousands[w]
            group = 0
    return num + group


print(parse_int('two hundred forty-six'))
