using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Globalization;
using System.Collections.Generic;
using System.Dynamic;
using System.IO;

namespace ConsoleApplication1
{
    class Solution {
        static bool Exist(List<int> w, int x, int y) {
            int n = w.Count;
            // find the min value which greater or equal than x
            int l = 0;
            int r = n - 1;
            while (l <= r) {
                int m = (l + r) >> 1;
                if (w[m] >= x) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (l == n)
            {
                return false;
            }
            int v = w[l];
            return x <= v && v <= y;
        }

        static void Main(String[] args) {
            // Console.SetIn(File.OpenText("input.txt"));

            string[] tokens_n = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(tokens_n[0]);
            int t = Convert.ToInt32(tokens_n[1]);
            string[] width_temp = Console.ReadLine().Split(' ');
            int[] width = Array.ConvertAll(width_temp,Int32.Parse);

            List<int>[] ws = new List<int>[3];
            for (int i = 0; i < 3; i++) {
                ws[i] = new List<int>();
            }
            for (int i = 0; i < n; i++) {
                int w = width[i];
                ws[w - 1].Add(i);
            }

            for(int a0 = 0; a0 < t; a0++){
                string[] tokens_i = Console.ReadLine().Split(' ');
                int x = Convert.ToInt32(tokens_i[0]);
                int y = Convert.ToInt32(tokens_i[1]);
                int max_w = 3;
                for (int i = 1; i <= 3; i++) {
                    if (Exist(ws[i - 1], x, y)) {
                        max_w = Math.Min(max_w, i);
                    }
                }
                Console.WriteLine(max_w);
            }
        }
    }
}
