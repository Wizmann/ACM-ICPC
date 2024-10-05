while True:
    n = int(input())
    if n == 0:
        break
    print('Alice' if n % 2 == 0 else 'Bob')
