print sum(
    filter(lambda x: str(x) == str(x)[::-1],
           filter(lambda x: bin(x)[2:] == bin(x)[2:][::-1],
                  range(1, 1000000))))
