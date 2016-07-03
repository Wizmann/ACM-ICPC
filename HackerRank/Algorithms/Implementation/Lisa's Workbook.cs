using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Globalization;
using System.Collections.Generic;
using System.Dynamic;

namespace ConsoleApplication1
{
    class Solution
    {
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

        static void Main(String[] args)
        {
            int n = Cin.NextInt();
            int k = Cin.NextInt();
            int[] t = new int[n];

            for (int i = 0; i < n; i++)
            {
                t[i] = Cin.NextInt();
            }

            int a = 0;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j <= t[i]; j++)
                {
                    int pp = a + (j + k - 1) / k;
                    if (pp == j)
                    {
                        ans++;
                    }
                }
                a += (t[i] + k - 1) / k;
            }
            Cout.Print(ans);
        }
    }
}
