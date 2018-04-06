def valid_parentheses(string):
    u = 0
    for c in string:
        if c == '(':
            u += 1
        elif c == ')':
            u -= 1
        if u < 0:
            return False
    return u == 0
