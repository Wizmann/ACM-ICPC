using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        string[] tokens_n = Console.ReadLine().Split(' ');
        int n = Convert.ToInt32(tokens_n[0]);
        int k = Convert.ToInt32(tokens_n[1]);
        string[] c_temp = Console.ReadLine().Split(' ');
        int[] c = Array.ConvertAll(c_temp,Int32.Parse);
        
        int E = 100;
        int p = 0;
        do {
            E -= 1;
            p = (p + k) % n; 
            if (c[p] == 1) {
                E -= 2;
            }
        } while (p != 0);
        Console.WriteLine(E);
    }
}
