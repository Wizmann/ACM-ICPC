package main;

import (
    "fmt"
)

func main() {
    var a, b, c int
    fmt.Scanf("%d%d%d", &a, &b, &c)
    dis := []int{
        a + b + c,
        2 * a + 2 * b,
        2 * a + 2 * c,
        2 * b + 2 * c,
    }
    
    ans := 0x3f3f3f3f
    for _, value := range dis {
        if value < ans {
            ans = value
        }
    }
    fmt.Println(ans)
}
