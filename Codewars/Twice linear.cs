using System;
using System.Collections.Generic;

public class DoubleLinear 
{
    public static int DblLinear (int n) 
    {
        var nums = new List<long>{1};
        int p = 0;
        int q = 0;
        
        while (nums.Count <= n) {
            long a = nums[p] * 2 + 1;
            long b = nums[q] * 3 + 1;
            
            if (a < b) {
                if (nums[nums.Count - 1] != a) {
                    nums.Add(a);
                }
                p += 1;
            } else {
                if (nums[nums.Count - 1] != b) {
                    nums.Add(b);
                }
                q += 1;
            }
        }
        return (int)nums[n];
    }
}
