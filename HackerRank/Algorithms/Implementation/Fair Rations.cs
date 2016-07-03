using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] B_temp = Console.ReadLine().Split(' ');
        int[] B = Array.ConvertAll(B_temp,Int32.Parse);
        
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (B[i] % 2 == 1) {
                B[i]++;
                B[i + 1]++;
                cnt +=  2;
            }
        }
        if (B[n - 1] % 2 == 1) {
            Console.WriteLine("NO");
        } else {
            Console.WriteLine(cnt);
        }
    }
}
