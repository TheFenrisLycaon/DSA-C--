def first_non_repeating_letter(string):
    for i in range(len(string)):
        if string[i].upper() not in string[:i]+string[i+1:] and string[i].lower() not in string[:i]+string[i+1:]:
            return string[i]
    return ('')


print(first_non_repeating_letter('a'))
print(first_non_repeating_letter('stress'))
print(first_non_repeating_letter('moonmen'))
print(first_non_repeating_letter(''))
print(first_non_repeating_letter('abba'))
print(first_non_repeating_letter('aa'))
print(first_non_repeating_letter('~><#~><'))
print(first_non_repeating_letter('hello world, eh?'))
print(first_non_repeating_letter('sTreSS'))
print(first_non_repeating_letter('Go hang a salami, I\'m a lasagna hog!'))
