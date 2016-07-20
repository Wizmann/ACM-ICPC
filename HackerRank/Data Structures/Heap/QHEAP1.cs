using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

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
    
    static void Main(String[] args) {
        var s = new SortedSet<int>();
        int n = Cin.NextInt();
        for (int i = 0; i < n; i++) {
            int c = Cin.NextInt();
            if (c == 3) {
                Cout.Print(s.Min);
            } else {
                int oph = Cin.NextInt();
                if (c == 1) {
                    s.Add(oph);
                } else {
                    s.Remove(oph);
                }
            }
        }
    }
}
