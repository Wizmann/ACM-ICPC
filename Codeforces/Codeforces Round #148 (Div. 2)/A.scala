import java.util.Scanner

object A extends App
{
	val cin=new Scanner(System.in);
	while(cin.hasNext())
	{
		val y,k,n=cin.nextInt();
		val ans =for { x_y <- List.range(0,n+1,k) ; if x_y>y } yield(x_y-y);
		if(ans.isEmpty) System.out.println(-1);
		else System.out.println(ans.mkString(" "));
	}
}
