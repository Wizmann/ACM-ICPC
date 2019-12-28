my = [0, 1, 1, 1, 2]
mx = [0, 0, -1, 1, 0]

n = int(input())

board = []
for i in range(n):
    board.append(list(input()))

flag = True
for i in range(n):
    for j in range(n):
        if board[i][j] == '#':
            for (dy, dx) in zip(my, mx):
                y = i + dy
                x = j + dx
                if y < 0 or y >= n or x < 0 or x >= n:
                    flag = False
                    break
                if board[y][x] == '.':
                    flag = False
                board[y][x] = '.'
            '''
            for line in board:
                print(''.join(line))
            print('--')
            '''
    if flag == False:
        break
print('YES' if flag else 'NO')
