using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication5
{
    class Program
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

        struct Point
        {
            public int x;
            public int y;

            public Point(int x_, int y_)
            {
                x = x_;
                y = y_;
            }
        }

        static int Bfs(string[] maze, int n, Point p1, Point p2)
        {
            var mx = new int[] {0, 1, 0, -1};
            var my = new int[] {1, 0, -1, 0};
            var dp = new int[n, n];
            var INF = 0x3f3f3f3f;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i, j] = INF;
                }
            }
            dp[p1.y, p1.x] = 0;

            var q = new Queue<Point>();
            q.Enqueue(p1);

            while (q.Count != 0)
            {
                var cur = q.Dequeue();
                for (int i = 0; i < 4; i++)
                {
                    int nx = cur.x;
                    int ny = cur.y;
                    while (true)
                    {
                        nx += mx[i];
                        ny += my[i];
                        if (nx >= n || nx < 0 || ny >= n || ny < 0)
                        {
                            break;
                        }
                        if (maze[ny][nx] == 'X')
                        {
                            break;
                        }
                        if (dp[cur.y, cur.x] + 1 < dp[ny, nx])
                        {
                            dp[ny, nx] = dp[cur.y, cur.x] + 1;
                            q.Enqueue(new Point(nx, ny));
                        }
                    }
                }
            }
            return dp[p2.y, p2.x];
        }
        static void Main(string[] args)
        {
            int n = Cin.NextInt();
            string[] maze = new string[n];
            for (int i = 0; i < n; i++)
            {
                maze[i] = Cin.NextToken();
            }

            int y1 = Cin.NextInt();
            int x1 = Cin.NextInt();
            int y2 = Cin.NextInt();
            int x2 = Cin.NextInt();

            var p1 = new Point(x1, y1);
            var p2 = new Point(x2, y2);

            Cout.Print(Bfs(maze, n, p1, p2));
        }
    }
}

