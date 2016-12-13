package main
import "fmt"

func main() {
    n := 0
    m := make(map[string]string)
    fmt.Scanf("%d", &n)
    for i := 0; i < n; i++ {
        key := ""
        value := ""
        fmt.Scanf("%s %s\n", &key, &value)
        m[key] = value
    }
    
    for true {
        key := ""
        _, err := fmt.Scanf("%s\n", &key)
        if err != nil {
            break
        }
        
        value, found := m[key]
        
        if found {
            fmt.Printf("%s=%s\n", key, value)
        } else {
            fmt.Printf("Not found\n")
        }
    }
}
