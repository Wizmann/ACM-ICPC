package main

import (
    "fmt"
    "os"
    "bufio"
)

func main() {
    var i uint32 = 4
    var d float32 = 4.0
    var s string = "HackerRank "

    scanner := bufio.NewReader(os.Stdin)

    var a uint32
    var b float32

    fmt.Scanf("%d", &a)
    fmt.Scanf("%f", &b)
    c, _ := scanner.ReadString('\n')

    fmt.Printf("%d\n", a + i)
    fmt.Printf("%.1f\n", b + d)
    fmt.Printf("%s%s\n", s, c)
}
