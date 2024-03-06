def valid_parentheses(string):
    if string.count('(') != string.count(')'):
        return False
    else:
        err = 0
        for i in string:
            if i == '(':
                err -= 1
            elif i == ')':
                err += 1
            if err > 0:
                return False
        return True