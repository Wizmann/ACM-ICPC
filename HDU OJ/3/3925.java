//Result:2012-08-03 21:42:54	Accepted	3925	281MS	3552K	1891 B	Java	Wizmann
import java.io.*;
import java.util.*;
import java.math.*;

public class Main 
{
	public static BigInteger min(BigInteger a,BigInteger b)
	{
		if(a.compareTo(BigInteger.valueOf(-1))==0) return b;
		else if(b.compareTo(BigInteger.valueOf(-1))==0) return a;
		else
		{
			if(a.compareTo(b)<0) return a;
			else return b;
		}
	}

	public static void main(String args[]) throws IOException
	{
		Scanner cin = new Scanner(new File("input.txt"));
		int T;
		T=cin.nextInt();
		BigInteger a;
		int b;
		for(int cas=0;cas<T;cas++)
		{
			System.out.print("Case #"+(cas+1)+": ");
			a=cin.nextBigInteger();
			b=cin.nextInt();
			
			String atxt=a.toString();
			String btxt=String.valueOf(b);
			if(atxt.length()>=btxt.length() && atxt.indexOf(btxt)!=-1)
			{
				System.out.println(0);
			}
			else if(a.compareTo(BigInteger.valueOf(b))<0)
			{
				System.out.println(BigInteger.valueOf(b).subtract(a));
			}
			else
			{
				BigInteger zehn=BigInteger.valueOf(10);
				BigInteger p=BigInteger.valueOf(1);
				int sz=atxt.length();
				BigInteger ans=BigInteger.valueOf(-1);
				for(int i=0;i<=sz;i++)
				{
					BigInteger tmp=p.multiply(BigInteger.valueOf(b));
					int len=tmp.toString().length();
					BigInteger ta=a.mod(zehn.pow(len));
					//System.out.println("A"+a+" TA:"+ta+","+"TMP:"+tmp);
					if(ta.compareTo(tmp)>0)
					{
						tmp=tmp.add(zehn.pow(len));
						BigInteger tans=tmp.subtract(ta);
						//System.out.println("TANS:"+tans+" "+"P"+p);
						if(tans.compareTo(p)<0) tans=BigInteger.valueOf(-1);
						ans=min(ans,tmp.subtract(ta));
					}
					else
					{
						BigInteger tans=tmp.subtract(ta);
						if(tans.compareTo(p)<0) tans=BigInteger.valueOf(-1);
						ans=min(ans,tmp.subtract(ta));
					}
					p=p.multiply(zehn);
				}
				System.out.println(ans);
			}
		}
	}
}











