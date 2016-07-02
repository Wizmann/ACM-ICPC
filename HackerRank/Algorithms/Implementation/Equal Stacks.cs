using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        string[] tokens_n1 = Console.ReadLine().Split(' ');
        int n1 = Convert.ToInt32(tokens_n1[0]);
        int n2 = Convert.ToInt32(tokens_n1[1]);
        int n3 = Convert.ToInt32(tokens_n1[2]);
        string[] h1_temp = Console.ReadLine().Split(' ');
        int[] h1 = Array.ConvertAll(h1_temp,Int32.Parse);
        string[] h2_temp = Console.ReadLine().Split(' ');
        int[] h2 = Array.ConvertAll(h2_temp,Int32.Parse);
        string[] h3_temp = Console.ReadLine().Split(' ');
        int[] h3 = Array.ConvertAll(h3_temp,Int32.Parse);
        
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        int s1 = h1.Sum();
        int s2 = h2.Sum();
        int s3 = h3.Sum();
        int ans = 0;
        while (s1 != 0 || s2 != 0 || s3 != 0) {
            if (s1 == s2 && s2 == s3) {
                ans = s1;
                break;
            }
            if (s1 >= s2 && s1 >= s3) {
                s1 -= h1[p1];
                p1++;
            } else if (s2 >= s1 && s2 >= s3) {
                s2 -= h2[p2];
                p2++;
            } else if (s3 >= s1 && s3 >= s2) {
                s3 -= h3[p3];
                p3++;
            }
        }
        Console.WriteLine(ans);
    }
}
