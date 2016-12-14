package main
import "fmt"

func factorial(n int) int {
    if n == 0 {
        return 1
    }
    return n * factorial(n - 1)
}

func main() {
    n := 0
    fmt.Scanf("%d", &n)
    fmt.Println(factorial(n))
}
