def separate_liquids(glass):
    d = {}
    DENSITY = ['H', 'W', 'A', 'O']
    
    for item in DENSITY:
      d[item] = 0
        
    for line in glass:
        for item in line:
            d[item] += 1

    n = len(glass)

    for i in xrange(n - 1, -1, -1):
        m = len(glass[i])
        for j in xrange(m - 1, -1, -1):
            for item in DENSITY:
                if d[item] != 0:
                    glass[i][j] = item
                    d[item] -= 1
                    break
    return glass
