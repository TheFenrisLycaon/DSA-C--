def disemvowel(string_):
    return "".join([x for x in string_ if x not in ["a", "e", "i", "o", "u"]])


print(disemvowel("This website is for losers LOL!"))
