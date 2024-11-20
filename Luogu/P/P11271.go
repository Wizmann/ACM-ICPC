package main

import (
	"bufio"
	"fmt"
	"os"
)

func abs(n int64) int64 {
	if n < 0 {
		return -n
	}
	return n
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var x, y, p, q int64

	// 从 stdin 读取四个整数 x, y, p, q
	fmt.Fscan(reader, &x, &y, &p, &q)

	// 计算四个绝对值
	absP := abs(p)
	absQ := abs(q)
	absYQ := abs(y - q)
	absXP := abs(x - p)

	// 计算最小值
	result := min(min(absP, absQ), min(absYQ, absXP))

	// 输出结果
	fmt.Println(result)
}
