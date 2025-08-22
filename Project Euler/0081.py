import sys

def main():
    # 从 stdin 读取，去掉首尾空格，再分行
    lines = [line.strip() for line in sys.stdin if line.strip()]
    matrix = [list(map(int, line.split(','))) for line in lines]

    n = len(matrix)       # 行数
    m = len(matrix[0])    # 列数

    dp = [[0] * m for _ in range(n)]

    # 初始化左上角
    dp[0][0] = matrix[0][0]

    # 第一行（只能从左边来）
    for j in range(1, m):
        dp[0][j] = dp[0][j-1] + matrix[0][j]

    # 第一列（只能从上面来）
    for i in range(1, n):
        dp[i][0] = dp[i-1][0] + matrix[i][0]

    # 其他位置
    for i in range(1, n):
        for j in range(1, m):
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matrix[i][j]

    print(dp[n-1][m-1])

if __name__ == "__main__":
    main()

