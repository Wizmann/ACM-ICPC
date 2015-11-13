package main

import (
    "fmt"
    "math/big"
)

func main() {
    var a, b big.Int
    fmt.Scanf("%d %d", &a, &b)
    fmt.Println(a.Mul(&a, &b))
}
