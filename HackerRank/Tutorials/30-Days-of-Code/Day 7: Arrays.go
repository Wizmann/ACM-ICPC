package main
import "fmt"

func main() {
    n := 0
    fmt.Scanf("%d", &n)
    
    var ns []int
    for i := 0; i < n; i++ {
        x := 0
        fmt.Scanf("%d", &x)
        ns = append(ns, x)
    }
    
    for i := n - 1; i >= 0; i-- {
        fmt.Printf("%d ", ns[i])
    }
    fmt.Printf("\n")
}
