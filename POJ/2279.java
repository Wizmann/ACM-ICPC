//POJ 2279
import java.math.*;
import java.util.*;

public class Main
{
	public final static int SIZE=32;
	public static void main(String args[])
	{
		Scanner input=new Scanner(System.in);
		int n;
		int[] s=new int[SIZE];
		int[][] g=new int[SIZE][SIZE];
		BigInteger ans;
		while(input.hasNext())
		{
			int sum=0;
			ans=BigInteger.ONE;
			n=input.nextInt();
			if(n==0) break;
			for(int i=0;i<SIZE;i++)
			{
				for(int j=0;j<SIZE;j++) g[i][j]=-1;
			}
			for(int i=0;i<n;i++)
			{
				s[i]=input.nextInt();
				sum+=s[i];
			}
			for(int i=1;i<=sum;i++) ans=ans.multiply(new BigInteger(Integer.toString(i)));
			for(int i=n-1;i>=0;i--)
			{
				for(int j=s[i]-1;j>=0;j--)
				{
					g[i][j]=0;
					if(i!=n-1) g[i][j]=g[i+1][j]+1;
					ans=ans.divide(new BigInteger(Integer.toString(g[i][j]+s[i]-j)));
				}
			}
			System.out.println(ans);
		}
	}
}
