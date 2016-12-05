package main

import (
    "os"
    "fmt"
    "bufio"
)

func main() {
    cin := bufio.NewReader(os.Stdin)
    line, _, _ := cin.ReadLine()
    fmt.Println("Hello, World.")
    fmt.Println(string(line))
}
