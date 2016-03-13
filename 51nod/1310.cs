using System;

class Solution {
	private ulong[] dp;
	private int[] res;
	private const int MAXBIT = 88;

	public void prepare() {
		dp = new ulong[MAXBIT + 1];
		res = new int[MAXBIT + 1];
		
		dp[1] = 1;
		dp[2] = 1;
		ulong sum = 1;
		for (int i = 3; i <= MAXBIT; i++) {
			dp[i] = sum + 1;
			sum += dp[i - 1];
		}
		for (int i = 1; i <= MAXBIT; i++) {
			dp[i] += dp[i - 1];
		}
		
		
		for (int i = 1; i <= MAXBIT; i++) {
			Console.Write("{0} ", dp[i]);
		}
		Console.WriteLine();
		
	}
	
	public void add(ulong x) {
		int[] cur = new int[MAXBIT + 1];
		for (int i = MAXBIT; i > 0 && x != 0; i--) {
			if (x > dp[i - 1]) {
				cur[i - 1] = 1;
				x -= dp[i - 1] + 1;
				// Console.WriteLine(">> {0} {1}", i, x);
			}
		}
		do_add(cur);
	}
	
	private void do_add(int[] cur) {
		for (int i = 0; i <= MAXBIT; i++) {
			res[i] ^= cur[i];
		}
	}
	
	public ulong get_ans() {
		ulong ans = 0;
		const ulong MOD = 1000000007;
		ulong x = 1;
		for (int i = 0; i <= MAXBIT; i++) {
			if (res[i] == 1) {
				ans = (ans + x) % MOD;
			}
			x = (x * 2) % MOD;
		}
		return ans;
	}
}

class Untitled
{
	static void Main(string[] args)
	{
		var S = new Solution();
		S.prepare();
		
		/*
		Console.WriteLine(S.solve(1));
		Console.WriteLine(S.solve(2));
		Console.WriteLine(S.solve(3));
		Console.WriteLine(S.solve(4));
		Console.WriteLine(S.solve(5));
		*/

		int n = Int32.Parse(Console.ReadLine());
		ulong[] A = new ulong[n];
		
		for (int i = 0; i < n; i++) {
			A[i] = UInt64.Parse(Console.ReadLine());
		}
				
		for (int i = 0; i < n; i++) {
			S.add(A[i]);
		}
		
		Console.WriteLine(S.get_ans());
	}
}