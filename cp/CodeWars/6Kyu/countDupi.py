def duplicate_count(text):
    k = {}
    for i in text.lower():
        k[i] = text.lower().count(i)
    
    return len([x for x in k.values() if x > 1])