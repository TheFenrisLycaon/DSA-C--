def duplicate_encode(word):
    return ''.join(['(' * (word.lower().count(i) == 1) +')'* (word.lower().count(i) != 1) for i in word.lower()])
    