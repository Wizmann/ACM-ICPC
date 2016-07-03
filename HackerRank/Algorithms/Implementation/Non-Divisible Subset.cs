using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Globalization;
using System.Collections.Generic;
using System.Dynamic;

class Solution {
    public static class Cin
    {
        public static string NextToken()
        {
            StringBuilder tokenChars = new StringBuilder();
            bool tokenFinished = false;
            bool skipWhiteSpaceMode = true;
            while (!tokenFinished)
            {
                int nextChar = Console.Read();
                if (nextChar == -1)
                {
                    tokenFinished = true;
                }
                else
                {
                    char ch = (char)nextChar;
                    if (char.IsWhiteSpace(ch))
                    {
                        if (!skipWhiteSpaceMode)
                        {
                            tokenFinished = true;
                            if (ch == '\r' && (Environment.NewLine == "\r\n"))
                            {
                                Console.Read();
                            }
                        }
                    }
                    else
                    {
                        skipWhiteSpaceMode = false;
                        tokenChars.Append(ch);
                    }
                }
            }

            string token = tokenChars.ToString();
            return token;
        }

        public static int NextInt()
        {
            string token = Cin.NextToken();
            return int.Parse(token);
        }
    }

    public static class Cout
    {
        public static void Print<T>(T item)
        {
            Console.WriteLine(item.ToString());
        }
    }
    
    static void Main(String[] args) {
        int n = Cin.NextInt();
        int k = Cin.NextInt();
        int[] ns = new int[n];
        var d = new Dictionary<int, int>();
        
        for (int i = 0; i < n; i++) {
            ns[i] = Cin.NextInt();
            int r = ns[i] % k;
            if (!d.ContainsKey(r)) {
                d[r] = 0;
            }
            d[r]++;
        }
        
        int ans = 0;
        for (int i = 1; i < (k + 1) / 2; i++) {
            int a = i;
            int b = k - i;
            int cnt_a = d.ContainsKey(a)? d[a]: 0;
            int cnt_b = d.ContainsKey(b)? d[b]: 0;
            
            // Cout.Print($"{a} {b} {cnt_a} {cnt_b}");
            
            ans += Math.Max(cnt_a, cnt_b);
        }
        
        if (d.ContainsKey(0)) {
            ans++;
        }
        
        if (k % 2 == 0 && d.ContainsKey(k / 2)) {
            ans++;
        }
        Cout.Print(ans);
    }
}
