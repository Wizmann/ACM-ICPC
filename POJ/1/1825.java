/*
Young
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 271		Accepted: 108

Description
Consider m natural numbers n1, n2, ..., nm with the property n1 >= n2 >= ... >= nm > 0.

We define a Young table as an arrangement in a table of n1 + n2 + ... + nm natural numbers (bigger than 0 and any two different), so that the ith line has ni elements (1 <= i <= m) in ascending order from left to right, and the elements from the same column are in ascending order from bottom to top.

An example of Young table for m = 4, n1 = 6, n2 = 4, n3 = 4, n4 = 1 is the following:

1	2	5	9	10	15

3	6	7	13		  

4	8	12	14		  

11					  


Given n1, n2, ..., nm determine the number of Young tables containing the elements 1, 2, ..., n1+n2+...+nm.

Input
The input has the stucture:

on the first line is: the natural number m (1 <= m <= 20);
on the second line are: the numbers n1, n2, ..., nm separated by a space (n1 <= 12).

Output
The output will contain the number of Young tables that can be built.

Sample Input

2
3 2

Sample Output

5

Hint
The five Young tables are:

1 3 5    1 2 3    1 2 4 
2 4      4 5      3 5

1 3 4    1 2 5 
2 5      3 4
*/

/*
题意Overview：
给N(≤20)，用1到N2的數字來填N×N的矩陣。對於矩陣上格子(i,j)的數值a(i,j)，必須滿足a(i,j)<a(i−1,j)且a(i,j)<a(i,j−1)。问方案数。

题解Solution：
钩子公式秒杀之，各种神奇>_<。
对于N个格子的方案数。等于N!除以（每个格子上方和左方的格子数目＋1）的积。
*/

//PKU OJ 1825
import java.math.*;
import java.io.*;
import java.util.*;

public class Main
{
	final static int SIZE = 240;
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		BigInteger ans;
		int[] s = new int[SIZE];
		int[][] young = new int[SIZE][SIZE];
		while(input.hasNext())
		{
			int sum = 0;
			int n = input.nextInt();
			for(int i=0;i<SIZE;i++)
			{
				for(int j=0;j<SIZE;j++) young[i][j]=-1;
			}
			ans = BigInteger.ONE;
			for(int i=0;i<n;i++)
			{
				s[i]=input.nextInt();
				sum+=s[i];
				young[i][s[i]-1]=0;
			}
			
			//hook-length formula
			
			for(int i=2;i<=sum;i++) ans=ans.multiply(new BigInteger(Integer.toString(i)));
			for(int i=n-1;i>=0;i--)
			{
				for(int j=s[i]-1;j>=0;j--)
				{
					//A hook length hook(x) of a box x in Young diagram Y(λ) of shape λ 
					//is the number of boxes that are in the same row to the right of it 
					//plus those boxes in the same column below it,
					young[i][j]=0;
                    if(i!=n-1) young[i][j]+=young[i+1][j]+1;
					ans=ans.divide(new BigInteger(Integer.toString(young[i][j]+s[i]-j)));
				}
			}
			
			//ans=n!/MUL(hook(x))
			System.out.println(ans.toString());
		}
	}
}
