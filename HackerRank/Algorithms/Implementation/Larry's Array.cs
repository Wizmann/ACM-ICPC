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
                        char ch = (char) nextChar;
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
            int T = Cin.NextInt();
            for (int case_ = 0; case_ < T; case_++)
            {
                int n = Cin.NextInt();
                int[] ns = new int[n];
                for (int i = 0; i < n; i++)
                {
                    ns[i] = Cin.NextInt();
                }
                int s = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < i; j++) {
                        if (ns[j] > ns[i]) {
                            s++;
                        }
                    }
                }
                Cout.Print(s % 2 == 1? "NO": "YES");
            }
        }

    }
}
