package main
import "fmt"

func main() {
    n := 0
    fmt.Scanf("%d", &n)
    
    var ns []int
    for i := 0; i < n; i++ {
        x := 0
        fmt.Scanf("%d", &x)
        ns = append(ns, x)
    }
    
    tot := 0
   
    for i := 0; i < n; i++ {
        numberOfSwaps := 0
    
        for j := 0; j < n - 1; j++ {
            if ns[j] > ns[j + 1] {
                ns[j], ns[j + 1] = ns[j + 1], ns[j]
                numberOfSwaps++
                tot++
            }
        }
    
        if numberOfSwaps == 0 {
            break;
        }
    }
    
    fmt.Printf("Array is sorted in %d swaps.\n", tot)
    fmt.Printf("First Element: %d\n", ns[0]);
    fmt.Printf("Last Element: %d\n", ns[n - 1]);  

}
