package main
import "fmt"

func solve(a, b int) int {
    if b | (b - 1) > a {
        return b - 2
    }
    return b - 1
}

func main() {
    n := 0
    fmt.Scanf("%d", &n)
    
    for i := 0; i < n; i++ {
        var a, b int
        fmt.Scanf("%d %d", &a, &b)
        fmt.Printf("%d\n", solve(a, b))
    }
}
