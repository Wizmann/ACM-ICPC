using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        int[][] a = new int[n][];
        for(int a_i = 0; a_i < n; a_i++){
           string[] a_temp = Console.ReadLine().Split(' ');
           a[a_i] = Array.ConvertAll(a_temp,Int32.Parse);
        }
        int x = 0;
        int y = 0;
        for (int i = 0; i < n; i++) {
            x += a[i][i];
            y += a[i][n - i - 1];
        }
        Console.WriteLine(Math.Abs(x - y));
    }
}
