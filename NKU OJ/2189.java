//Result:Wizmann 	2189 	Accepted 	Java (jdk6) 	0.46k 	1390 ms 	380416 KB 	
import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	final static int SIZE = 1024;
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		BigInteger[] dp=new BigInteger[SIZE];
		dp[1]=dp[2]=BigInteger.ONE;
		dp[3]=new BigInteger("2");
		for(int i=4;i<SIZE;i++)
		{
			dp[i]=dp[i-1].add(dp[i-3]).add(BigInteger.ONE);
		}
		while(input.hasNext())
		{
			int n = input.nextInt();
			System.out.println(dp[n]);
		}
	}
}
			
