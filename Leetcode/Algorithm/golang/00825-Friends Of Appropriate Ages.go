import (
    "fmt"
    "sort"
)

func numFriendRequests(ages []int) int {
    buckets := make([]int, 200);
    
    for _, age := range ages {
        buckets[age]++;
    }
    
    res := 0
    for i := 1; i < 200; i++ {
        if float64(i) > float64(i) * 0.5 + 7 {
            res += buckets[i] * (buckets[i] - 1)
        }
        buckets[i] += buckets[i - 1]
    }
    
    p := 7
    q := 7
    
    for q < 200 {
        for p < q && float64(p) <= float64(q) * 0.5 + 7 {
            p++;
        }
        
        res += (buckets[q] - buckets[q - 1]) * (buckets[q - 1] - buckets[p - 1]);
        q += 1;
    }
    
    return res;
}