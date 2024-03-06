def zero(test=''): 
    if test=='':
        return '0'
    else:
        if '+' in test:
            return int(test[-1])
        elif '-' in test:
            return -int(test[-1])
        elif '*' in test:
            return 0
        else:
            return 0
        
def one(test=''):
    if test=='':
        return '1'
    else:
        if '+' in test:
            return 1+int(test[-1])
        elif '-' in test:
            return 1-int(test[-1])
        elif '*' in test:
            return int(test[-1])
        else:
            return 1//int(test[-1])
    
def two(test=''):
    if test=='':
        return '2'
    else:
        if '+' in test:
            return 2+int(test[-1])
        elif '-' in test:
            return 2-int(test[-1])
        elif '*' in test:
            return 2*int(test[-1])
        else:
            return 2//int(test[-1])
        
def three(test=''):
    if test=='':
        return '3'
    else:
        if '+' in test:
            return 3+int(test[-1])
        elif '-' in test:
            return 3-int(test[-1])
        elif '*' in test:
            return 3*int(test[-1])
        else:
            return 3//int(test[-1])
        
def four(test=''):
    if test=='':
        return '4'
    else:
        if '+' in test:
            return 4+int(test[-1])
        elif '-' in test:
            return 4-int(test[-1])
        elif '*' in test:
            return 4*int(test[-1])
        else:
            return 4//int(test[-1])
        
def five(test=''):
    if test=='':
        return '5'
    else:
        if '+' in test:
            return 5+int(test[-1])
        elif '-' in test:
            return 5-int(test[-1])
        elif '*' in test:
            return 5*int(test[-1])
        else:
            return 5//int(test[-1])
        
def six(test=''):
    if test == '':
        return '6'
    else:
        if '+' in test:
            return 6+int(test[-1])
        elif '-' in test:
            return 6-int(test[-1])
        elif '*' in test:
            return 6*int(test[-1])
        else:
            return 6//int(test[-1])
         
def seven(test=''):
    if test=='':
        return '7'
    else:
        if '+' in test:
            return 7+int(test[-1])
        elif '-' in test:
            return 7-int(test[-1])
        elif '*' in test:
            return 7*int(test[-1])
        else:
            return 7//int(test[-1])
        
def eight(test=''):
    if test=='':
        return '8'
    else:
        if '+' in test:
            return 8+int(test[-1])
        elif '-' in test:
            return 8-int(test[-1])
        elif '*' in test:
            return 8*int(test[-1])
        else:
            return 8//int(test[-1])
        
def nine(test=''):
    if test=='':
        return '9'
    else:
        if '+' in test:
            return 9+int(test[-1])
        elif '-' in test:
            return 9-int(test[-1])
        elif '*' in test:
            return 9*int(test[-1])
        else:
            return 9//int(test[-1])
        
def plus(test=''):
    return '+ ' + test

def minus(test=''):
    return '- ' + test
    
def times(test=''):
    return '* ' + test 
    
def divided_by(test=''):
    return test