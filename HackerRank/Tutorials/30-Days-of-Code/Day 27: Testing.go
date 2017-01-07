package main

import (  
    "fmt"  
    "math/rand"  
    "time"  
)  
  
func main() {  
    rand.Seed(time.Now().UnixNano())  
      
    T := 5
    
    fmt.Println(T)
    
    for i := 0; i < T; i++ {
        n := 100 + i * 10
        k := rand.Int() % n + 1
        
        fmt.Printf("%d %d\n", n, k)
        
        fmt.Printf("0 100 -100")
        for j := 3; j < n; j++ {
            t := rand.Int() % 2000 + 1 - 1000
            fmt.Printf(" %d", t)
        }
        fmt.Println("")
    }
}

