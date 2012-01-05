//Result:1807	Accepted	441MS	3692K	Java	 907B	2012-01-05 10:30:58
import java.math.*;
import java.util.*;

class CPoint
{
	public int x,y;

	CPoint()
	{
		x=y=0;
	}

	public void setPoint(int i_x,int i_y)
	{
		x=i_x;y=i_y;
	}
}

public class Main
{
	public final static int SIZE=128;
	public static void main(String args[])
	{
		Scanner input=new Scanner(System.in);
		int T=input.nextInt();
		CPoint[] array=new CPoint[SIZE];
		for(int t=0;t<T;t++)
		{
			int n=input.nextInt();
			for(int i=0;i<n;i++)
			{
				int a=input.nextInt();
				int b=input.nextInt();
				array[i]=new CPoint();
				array[i].setPoint(a,b);
			}

			int ans=0;
			for(int i=0;i<n;i++)
			{
				int sum=0;
				for(int j=0;j<n;j++) if(i!=j)
				{
					if(array[j].x>array[i].x && array[j].y>array[i].y) sum++;
					if(array[j].x<array[i].x && array[j].y<array[i].y) sum++;
				}
				if(sum>ans) ans=sum;
			}
			System.out.println(ans);
		}
	}
}
