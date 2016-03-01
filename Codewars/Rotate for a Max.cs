using System;
using System.Collections.Generic;
using System.Linq;

public class MaxRotate 
{
    private static string rotate(string s, int p) {
        char[] ca = s.ToCharArray();
        int n = s.Length;
        char c = ca[p];
        for (int i = p; i < n - 1; i++) {
            ca[i] = ca[i + 1];
        }
        ca[n - 1] = c;
        return new String(ca);
    }
    
    public static long MaxRot (long n) 
    {
        var s = n.ToString();
        int len = s.Length;
        
        var nums = new List<string>{s};
        
        for (int i = 0; i < len; i++) {
            s = rotate(s, i);
            nums.Add(s);
        }
        
        return nums.Select(x => Convert.ToInt64(x)).Max();
    }
}
