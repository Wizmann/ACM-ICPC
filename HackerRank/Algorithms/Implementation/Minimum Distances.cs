using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] A_temp = Console.ReadLine().Split(' ');
        int[] A = Array.ConvertAll(A_temp,Int32.Parse);
        
        var d = new Dictionary<int, int>();
        
        const int INF = 0x3f3f3f3f;
        int ans = INF;
        for (int i = 0; i < n; i++) {
            if (d.ContainsKey(A[i])) {
                ans = Math.Min(ans, i - d[A[i]]);
            }
            d[A[i]] = i;
        }
        
        if (ans == INF) {
            ans = -1;
        }
        
        Console.WriteLine(ans);
    }
}
