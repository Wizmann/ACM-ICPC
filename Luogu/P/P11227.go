package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Scan(&n)

	set := make(map[string]bool)
	scanner := bufio.NewScanner(os.Stdin)

	for i := 0; i < n; i++ {
		scanner.Scan()
		input := scanner.Text()
		set[input] = true
	}

	result := 52 - len(set)
	fmt.Println(result)
}
