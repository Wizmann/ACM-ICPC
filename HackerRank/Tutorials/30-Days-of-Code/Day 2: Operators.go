package main

import "fmt"

func main() {
    tot := 0.0
    a := 0
    b := 0
    fmt.Scanf("%f", &tot)
    fmt.Scanf("%d", &a)
    fmt.Scanf("%d", &b)
    
    fmt.Printf("The total meal cost is %d dollars.\n", 
               int(tot * (100. + float64(a) + float64(b)) / 100. + 0.5))
}
