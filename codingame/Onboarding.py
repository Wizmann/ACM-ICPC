# game loop
while 1:
    enemy_1 = input()  # name of enemy 1
    dist_1 = int(input())  # distance to enemy 1
    enemy_2 = input()  # name of enemy 2
    dist_2 = int(input())  # distance to enemy 2

    # Write an action using print

    if dist_1 < dist_2:
        print(enemy_1)
    else:
        print(enemy_2)
    # Enter the code here
