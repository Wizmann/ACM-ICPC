package main

import "fmt"

func main() {
    T := 0
    fmt.Scanf("%d\n", &T)

    for i := 0; i < T; i++ {
        l := 0
        r := 0
        fmt.Scanf("%d %d\n", &l, &r)

        fmt.Printf("%d %d\n", l, l * 2)
    }
}
