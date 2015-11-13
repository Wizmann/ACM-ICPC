package main

import (
    "fmt"
)

func merge_sort(nums, buffer[] int) int {
    if len(nums) <= 1 {
        return 0
    }
    n := len(nums)
    m := len(nums) / 2
    a := merge_sort(nums[:m], buffer)
    b := merge_sort(nums[m:], buffer)
    i := 0
    j := m
    
    ptr := 0
    ans := 0
    for i < m && j < n {
        if nums[i] <= nums[j] {
            buffer[ptr] = nums[i]
            i++
        } else {
            buffer[ptr] = nums[j]
            j++
            ans += m - i
        }
        ptr++
    }

    for i < m {
        buffer[ptr] = nums[i]
        ptr++
        i++
    }

    for j < n {
        buffer[ptr] = nums[j]
        ptr++
        j++
    }
    
    for i := 0; i < n; i++ {
        nums[i] = buffer[i]
    }
    return ans + a + b
}

func main() {
    var a[50010] int
    var b[50010] int
    n := 0
    fmt.Scanf("%d ", &n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d ", &a[i])
    }
    fmt.Println(merge_sort(a[:n], b[:]))
}
