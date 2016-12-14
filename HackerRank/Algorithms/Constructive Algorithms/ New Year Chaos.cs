using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {
    private static readonly int MAX_BRIBING_NUM = 2;
    
    class BITree {
        private int[] _biarray;
        public int Num {get; set;}
        
        public BITree(int num) {
            Num = num;
            _biarray = new int[num + 1];
        }
        
        public void Add(int pos, int value) {
            while (pos < Num) {
                _biarray[pos] += value;
                pos += Lowbit(pos);
            }
        }
        
        public int Sum(int pos_a, int pos_b) {
            return Sum(pos_b) - Sum(pos_a - 1);
        }
        
        private int Sum(int pos) {
            int sum = 0;
            while (pos > 0) {
                sum += _biarray[pos];
                pos -= Lowbit(pos);
            }
            return sum;
        }
        
        private int Lowbit(int x) => x & -x;
    }
    
    class Run {
        private int n;
        private int[] ns;
        public Run(int n_, int[] ns_) {
            n = n_;
            ns = ns_;
        }
        
        public int Solve() {
            var bitree = new BITree(n + 1);
            int[] pos = new int[n + 1];
            for (int i = 0; i < n; i++) {
                var x = ns[i];
                pos[x] = i + 1;
            }
            
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int s = bitree.Sum(pos[i], n);
                if (s > MAX_BRIBING_NUM) {
                    return -1;
                }
                bitree.Add(pos[i], 1);
                ans += s;
            }
            return ans;
        }
    }

    static void Main(String[] args) {
        int T = Convert.ToInt32(Console.ReadLine());
        for(int a0 = 0; a0 < T; a0++){
            int n = Convert.ToInt32(Console.ReadLine());
            string[] q_temp = Console.ReadLine().Split(' ');
            int[] q = Array.ConvertAll(q_temp,Int32.Parse);
            
            var s = new Run(n, q);
            var res = s.Solve();
            if (res == -1) {
                Console.WriteLine("Too chaotic");
            } else {
                Console.WriteLine(res);
            }
        }
    }
}
