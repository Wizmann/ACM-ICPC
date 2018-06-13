func moveZeroes(nums []int)  {
    n := len(nums);
    p := 0;
    for i := 0; i < n; i++ {
        if nums[i] != 0 {
            nums[p], nums[i] = nums[i], nums[p]
            p++;
        }
    }
}
