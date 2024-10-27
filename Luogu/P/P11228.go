package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// 定义方向的增量：右、下、左、上
var directions = [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

// 定义一个结构体 Point 用于表示坐标
type Point struct {
	x, y int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	// 读取数据组数 T
	T, _ := strconv.Atoi(scanner.Text())

	for t := 0; t < T; t++ {
		// 读取 n, m, k
		scanner.Scan()
		params := strings.Fields(scanner.Text())
		n, _ := strconv.Atoi(params[0])
		m, _ := strconv.Atoi(params[1])
		k, _ := strconv.Atoi(params[2])

		// 读取 x0, y0, d0
		scanner.Scan()
		initialParams := strings.Fields(scanner.Text())
		x, _ := strconv.Atoi(initialParams[0])
		y, _ := strconv.Atoi(initialParams[1])
		d, _ := strconv.Atoi(initialParams[2])

		// 读取地图
		grid := make([][]byte, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			grid[i] = []byte(scanner.Text())
		}

		// 使用 map[Point]bool 记录已访问的坐标
		visited := make(map[Point]bool)
		visited[Point{x, y}] = true // 初始位置标记为已访问

		// 模拟机器人移动 k 步
		for step := 0; step < k; step++ {
			// 计算下一步位置
			newX := x + directions[d][0]
			newY := y + directions[d][1]

			// 检查新位置是否在范围内，且不是障碍
			if newX >= 1 && newX <= n && newY >= 1 && newY <= m && grid[newX-1][newY-1] == '.' {
				// 移动到新位置
				x = newX
				y = newY
				visited[Point{x, y}] = true // 标记为已访问
			} else {
				// 向右转90度
				d = (d + 1) % 4
			}
		}

		// 输出结果：不重复格子的个数
		fmt.Println(len(visited))
	}
}
