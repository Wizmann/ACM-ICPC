using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        string[] tokens_x1 = Console.ReadLine().Split(' ');
        int x1 = Convert.ToInt32(tokens_x1[0]);
        int v1 = Convert.ToInt32(tokens_x1[1]);
        int x2 = Convert.ToInt32(tokens_x1[2]);
        int v2 = Convert.ToInt32(tokens_x1[3]);
        
        if (v1 == v2) {
            Console.WriteLine(x1 == x2? "YES": "NO");
        } else {
            int dx = x2 - x1;
            int dy = v1 - v2;
            
            if (dx % dy != 0) {
                Console.WriteLine("NO");
            } else {
                int u = dx / dy;
                Console.WriteLine(u >= 0? "YES": "NO");
            }
        }
    }
}
