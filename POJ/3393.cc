//Result:wizmann	3393	Accepted	736K	0MS	G++	1500B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define elif else if

const int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
enum week{Sun,Mon,Tue,Wed,Thu,Fri,Sat};

bool leap(int year)
{
	if(year<1582) return !(year%4);
	elif(year==1700) return true;
	else return (year%4==0&&year%100!=0) || year%400==0;
}

int ComputeDays(int y,int m)
{
	int day=1;
	for(int i=1;i<y;i++)
	{
		if(leap(i)) day+=366;
		else day+=365;
	}
	for(int i=1;i<m;i++)
	{
		if(i==2 && leap(y)) day++;
		day+=month[i];
	}
	
	if(y>1752) day-=11;
	elif(y==1752 && m>9) day-=11;

	return day;
}

int main()
{
	int ys,ms,ye,me;
	int T;
	input(T);
	while(T--)
	{
		input(ys>>ms>>ye>>me);
		int luck=0,good=0;
		int day=ComputeDays(ys,ms);

		if( (day+5)%7<=Mon || ((day+5)%7==Sat) ) good++;
		for(int i=ys;i<ye;i++)
		{
			int j=1;
			if(i==ys) j=ms;

			for(;j<=12;j++)
			{
				day+=month[j];
				if(leap(i) && j==2) day++;
				if(i==1752 && j==9) day-=11;

				if( (day+5)%7<=Mon || (day+5)%7==Sat )
				{
					good++;luck++;
				}
			}
		}
		int j=1;
		if(ye==ys) j=ms;
		for(;j<=me;j++)
		{
			day+=month[j];
			if(leap(ye) && j==2) day++;
			if(ye==1752 && j==9) day-=11;
			if( (day+5)%7<=Mon || (day+5)%7==Sat )
			{
				if(j!=me) good++;
				luck++;
			}
		}
		print(luck<<' '<<good);
	}
	return 0;
}

