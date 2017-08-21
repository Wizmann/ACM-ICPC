using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Globalization;
using System.Collections.Generic;
using System.Dynamic;


namespace ConsoleApplication1
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
        public static long NextLong()
        {
            string token = Cin.NextToken();
            return long.Parse(token);
        }

        public static double NextDouble(bool acceptAnyDecimalSeparator = true)
        {
            string token = Cin.NextToken();
            if (acceptAnyDecimalSeparator)
            {
                token = token.Replace(',', '.');
                double result = double.Parse(token, CultureInfo.InvariantCulture);
                return result;
            }
            else
            {
                double result = double.Parse(token);
                return result;
            }
        }

        public static decimal NextDecimal(bool acceptAnyDecimalSeparator = true)
        {
            string token = Cin.NextToken();
            if (acceptAnyDecimalSeparator)
            {
                token = token.Replace(',', '.');
                decimal result = decimal.Parse(token, CultureInfo.InvariantCulture);
                return result;
            }
            else
            {
                decimal result = decimal.Parse(token);
                return result;
            }
        }
    }

    public static class Cout
    {
        public static void Print<T>(T item)
        {
            Console.WriteLine(item.ToString());
        }

        public static void Write<T>(T item)
        {
            Console.Write(item.ToString());
        }
    }

    public static class Solution
    {
        private static int r;
        private static int c;
        
        static int tick(int[,,] buffer, int cur, int n)
        {
            int next = -1;
            for (int t = 0; t <= n; t++) {
                next = cur ^ 1;
                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        buffer[i, j, next] = buffer[i, j, cur];
                    }
                }

                if (t % 2 == 0 && t != 0) {
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            if (buffer[i, j, next] == 0) {
                                buffer[i, j, next] = 4;
                            }
                        }
                    }
                }

                if (t % 2 == 1 && t != 1) {
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            if (buffer[i, j, cur] == 1) {
                                if (i + 1 <  r)  buffer[i + 1, j, next] = 1;
                                if (i - 1 >= 0)  buffer[i - 1, j, next] = 1;
                                if (j + 1 <  c)  buffer[i, j + 1, next] = 1;
                                if (j - 1 >= 0)  buffer[i, j - 1, next] = 1;
                                buffer[i, j, next] = 1;
                            }
                        }
                    }
                }

                for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) {
                        if (buffer[i, j, next] != 0) {
                            buffer[i, j, next]--;
                        }
                    }
                }
                cur = next;
            }
            return next;
        }
        
        static void Main(String[] args)
        {
            r = Cin.NextInt();
            c = Cin.NextInt();
            int n = Cin.NextInt();

            int[,] board = new int[r, c];
            for (int i = 0; i < r; i++) {
                var line = Cin.NextToken();
                for (int j = 0; j < c; j++) {
                    if (line[j] == '.') {
                        board[i, j] = 0;
                    } else {
                        board[i, j] = 4;
                    }
                }
            }
            
            int[,,] buffer = new int[r, c, 2];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    buffer[i, j, 0] = board[i, j];
                }
            }


            n = (n - 2) % 4 + 2;
            int p = tick(buffer, 0, n);

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    Cout.Write(buffer[i, j, p] == 0? '.': 'O');
                }
                Cout.Print("");
            }
        }
    }
}

