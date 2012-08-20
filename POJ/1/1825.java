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
