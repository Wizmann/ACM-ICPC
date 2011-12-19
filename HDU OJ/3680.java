import java.io.*;
import java.util.*;
import java.math.*;

public class ProA
{
	public static Scanner in = new Scanner(System.in);
	public static BigInteger Abs(BigInteger num)
    {
        return num.abs();
    }
    public static BigInteger Min(BigInteger num1,BigInteger num2)
    {
        return num1.min(num2);
    }

	public static void main(String args[])
	{
		BigInteger m,n;
		while(true)
		{
			n = in.nextBigInteger();
			m = in.nextBigInteger();
			if((n.compareTo(BigInteger.ZERO)==0)||(m.compareTo(BigInteger.ZERO)==0)) break;
			else
			{
				if(m.compareTo(n)>0) System.out.println(m.subtract(n));
				else
				{
					BigInteger ans = n.subtract(m);
					BigInteger x=n;
					BigInteger x1,x2,y1,y2;
					//x为奇数：f(x,n) = f(x/2,n) + 2
					//如果x为偶数 ：f(x,n) = f(x/2,n) + 1
					//=> f(x,n) == min( f(x,n) , f(x+1,n) )
					x1=BigInteger.ZERO;
					x2=BigInteger.ONE;
					while(x.multiply(BigInteger.valueOf(2)).compareTo(m)>0)
					{
						if(x.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO)==0)
						{
							y1=Min(x1.add(BigInteger.valueOf(1)),x2.add(BigInteger.valueOf(2)));
							//x为偶数，则x1+=1(除二)  x2+=2(减一，除二)
							y2=Min(x1.add(BigInteger.valueOf(2)),x2.add(BigInteger.valueOf(2)));
							//x+1为奇数，x1+=2(除二，加一)  x2+=2(加一，除二)
						}
						else
						{
							y1=Min(x1.add(BigInteger.valueOf(2)),x2.add(BigInteger.valueOf(2)));
							//x为奇数，x1+=2(减一除2)  x2+=2(除二减1)
							y2=Min(x1.add(BigInteger.valueOf(2)),x2.add(BigInteger.valueOf(1)));
							//x为偶数，x1+=2(加一除二)，x2+=1(除二)
						}
						x = x.divide(BigInteger.valueOf(2));
						//System.out.println(x);
						x1 = y1;
						x2 = y2;
						ans = Min(ans,Abs(x.subtract(m)).add(y1));
						ans = Min(ans,Abs(x.subtract(m).add(BigInteger.ONE/*|x+1-m|*/)).add(y2));
					}
					System.out.println(ans);
				}
			}				
		}
	}
}
