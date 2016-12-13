package main
import "fmt"

func main() {
    x := 0
    fmt.Scanf("%d", &x)
    
    for i := 1; i <= 10; i++ {
        fmt.Printf("%d x %d = %d\n", x, i, x * i)
    }
}
