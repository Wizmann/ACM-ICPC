package main
import "fmt"

func solve(d1, m1, y1, d2, m2, y2 int) int {
    date0_1 := y1 * 10000 + m1 * 100 + d1
    date0_2 := y2 * 10000 + m2 * 100 + d2
    
    if date0_1 <= date0_2 {
        return 0
    }
    
    date1_1 := y1 * 100 + m1
    date1_2 := y2 * 100 + m2
    
    if date1_1 == date1_2 {
        return 15 * (date0_1 - date0_2)
    }
    
    if (y1 == y2) {
        return 500 * (date1_1 - date1_2)
    }
    
    return 10000    
}

func main() {
    var y1, m1, d1 int
    var y2, m2, d2 int
    
    fmt.Scanf("%d %d %d", &d1, &m1, &y1)
    fmt.Scanf("%d %d %d", &d2, &m2, &y2)
    
    fmt.Println(solve(d1, m1, y1, d2, m2, y2))    
}
