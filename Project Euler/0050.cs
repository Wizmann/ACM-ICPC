using System;
using System.Collections.Generic;
using System.Linq;

namespace Lydia_么么要玉潇
{
    public class Test
    {
        static void Main()
        {
            long ans = 0;
            init();
            for (int i = 0; i < primes_sum.Count; i++) {
                for (int j = 0; j < i; j++) {
                    long v = primes_sum[i] - primes_sum[j];
                    if (isPrime(v)) {
                        ans = Math.Max(ans, v);
                    }
                }
            }
            Console.WriteLine(ans);
        }

        static void init() {
            primes = new List<int>();
            primes_sum = new List<long>();
            for (int i = 2; i < SIZE; i++) {
                if (isPrime(i)) {
                    primes.Add(i);
                }
            }

            long sum = 0;
            foreach (int prime in primes) {
                sum += prime;
                if (sum > SIZE) {
                    break;
                }
                primes_sum.Add(sum);
            }
        }

        static bool isPrime(long v) {
            for (long i = 2; i <= Math.Sqrt(v) + 1; i++) {
                if (v % i == 0) {
                    return false;
                }
            }
            return true;
        }

        const int SIZE = 1000000;
        static List<int> primes;
        static List<long> primes_sum;
    }
}
