package main
import "fmt"

func main() {
    x := 0
    fmt.Scanf("%d", &x)
    switch {
        case x % 2 == 1:
            fmt.Println("Weird")
        case x <= 5:
            fmt.Println("Not Weird")
        case x <= 20:
            fmt.Println("Weird")
        default:
            fmt.Println("Not Weird")
    }
}
