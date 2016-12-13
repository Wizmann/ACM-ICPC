package main
import "fmt"

func main() {
    n := 0
    fmt.Scanf("%d", &n)
    for i := 0; i < n; i++ {
        s := ""
        fmt.Scanf("%s", &s)
        l := len(s)
        
        for j := 0; j < l; j += 2 {
            fmt.Printf("%c", s[j])
        }
        
        fmt.Printf(" ")
        
        for j := 1; j < l; j += 2 {
            fmt.Printf("%c", s[j])
        }
        
        fmt.Printf("\n")
    }
}
