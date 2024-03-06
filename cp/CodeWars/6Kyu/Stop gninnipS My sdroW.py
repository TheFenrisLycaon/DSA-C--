def spin_words(sentence):
    return ' '.join([x[::-1] if len(x) >= 5 else x for x in sentence.split(' ')]) 