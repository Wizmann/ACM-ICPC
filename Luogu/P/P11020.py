#python3
import sys
def fill_diagonal_ones(n, m, k):
    matrix = [[0 for _ in range(m)] for _ in range(n)]
    
    count = 0

    diagonals = []
    
    for diag in range(n):
        diagonals.append((diag, 0))  # (起始行，起始列)
    
    for diag in range(1, m):
        diagonals.append((0, diag))  # (起始行，起始列)

    for start_i, start_j in sorted(diagonals, key=lambda x: min(n - x[0], m - x[1]), reverse=True):
        i, j = start_i, start_j
        
        while i < n and j < m and count < k:
            matrix[i][j] = 1
            count += 1
            i += 1
            j += 1
        
        if count >= k:
            break

    return matrix


T = int(input())
for case_ in range(T):
    n, m, k = list(map(int, input().split()))
    result = fill_diagonal_ones(n, m, k)
    for row in result:
        for c in row:
            if c == 0:
                sys.stdout.write('.')
            else:
                sys.stdout.write('S')
        sys.stdout.write('\n')

'''
^^^^^TEST^^^^
2
3 5 2
5 4 7
-------------
<ignore>
$$$$TEST$$$$
'''
