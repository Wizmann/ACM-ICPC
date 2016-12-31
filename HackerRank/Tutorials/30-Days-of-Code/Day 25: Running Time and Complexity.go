package main
import "fmt"

func isPrime(x int) bool {
    for i := int64(2); i * i <= int64(x); i += 1 {
        if int64(x) % i == 0 {
            return false
        }
    } 
    return true
}

func main() {
    n := 0
    fmt.Scanf("%d", &n)
    for i := 0; i < n; i++ {
        x := 0
        fmt.Scanf("%d", &x)
        if x != 1 && isPrime(x) {
            fmt.Println("Prime")
        } else {
            fmt.Println("Not prime")
        }
    }
}
