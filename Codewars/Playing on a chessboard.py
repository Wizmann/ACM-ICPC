def game(n):
    a = n * n
    if a % 2 == 0:
        return [a / 2]
    else:
        return [a, 2]
