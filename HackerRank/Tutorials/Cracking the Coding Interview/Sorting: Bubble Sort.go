package main
import "fmt"

func main() {
    var n int;
    fmt.Scanf("%d", &n);
    var ns = make([]int, n);
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &ns[i]);
    }

    cnt := 0;
    for i := 0; i < n; i++ {
        for j := 0; j < n - 1; j++ {
            if ns[j] > ns[j + 1] {
                ns[j], ns[j + 1] = ns[j + 1], ns[j]
                cnt++;
            }
        }
    }
    
    fmt.Printf("Array is sorted in %d swaps.\n", cnt);
    fmt.Printf("First Element: %d\n", ns[0]);
    fmt.Printf("Last Element: %d\n", ns[n - 1]);
}
