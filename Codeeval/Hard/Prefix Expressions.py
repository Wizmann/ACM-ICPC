import sys
sys.stdin = open('input.txt')

for line in sys.stdin:
    tokens = line.strip().split()
    
    if not tokens:
        continue

    ops = []
    nums = []

    for token in tokens:
        if not token.isdigit():
            ops.append(token)
        else:
            nums.append(float(token))
            if len(nums) == 2:
                b = nums.pop()
                a = nums.pop()
                op = ops.pop()
                c = eval('%f %s %f' % (a, op, b))
                nums.append(c)
    print nums[0], int(nums[0] + 1e-4)
