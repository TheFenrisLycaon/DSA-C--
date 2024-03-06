def likes(names):
    if len(names) == 1:
        return names[0] + ' likes this'
    elif len(names) == 2:
        return names[0] + ' and ' + names[1] + ' like this'
    elif len(names) == 3:
        return ', '.join(names[:-2]) + ', ' + likes(names[-2:])
    elif len(names) > 3:
        return ', '.join(names[:2]) + ' and ' + str(len(names[2:])) + ' others like this'
        
    else:
        return 'no one likes this'
    