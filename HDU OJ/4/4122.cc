//Result:2012-10-04 19:56:05	Accepted	4122	218MS	8248K	2717 B	G++	Wizmann
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define ORDER 2560
#define SIZE 100010

typedef long long llint;

int query,n;

namespace DATE
{
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	struct date
	{
		int year,month,day,hour;
		date(){}
		date(int iyear,int imonth,int iday,int ihour)
		{
			year=iyear;month=imonth,day=iday;hour=ihour;
		}
	};
	
	const date START_TIME=date(2000,1,1,0);
	
	inline bool leap(int year)
	{
		return (year%4==0 && year%100!=0) || year%400==0;
	}


	int date2int(const date &a)
	{
		int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400;
		days[1]+=leap(a.year);
		for(int i=0;i<a.month-1;i++) ret+=days[i];
		days[1]=28;
		return ret+a.day;
	}

	int date2hour(const date& a)
	{
		int days=date2int(a)-date2int(START_TIME);
		return days*24+a.hour+1;
	}
}

namespace RMQ
{
	enum{RMQSIZE=20};
	int mini[SIZE][RMQSIZE];
	int pow2[RMQSIZE];
	void init()
	{
		memset(mini,0,sizeof(mini));
		for(int i=0;i<RMQSIZE;i++) pow2[i]=1<<i;
	}
	
	int log2(int x)
	{
		return upper_bound(pow2,pow2+RMQSIZE,x)-pow2-1;
	}
	void initRMQ()
	{
		int m=log2(n);
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j>=1;j--)
			{
				mini[j][i]=mini[j][i-1];
				if(j+(1<<(i-1))<=n) mini[j][i]=min(mini[j][i],mini[j+(1<<(i-1))][i-1]);
			}
		}
	}

	int query_min(int l,int r)
	{
		int m=log2(r-l+1);
		return min(mini[l][m],mini[r-(1<<m)+1][m]);
	}
}

int order_num[ORDER];
int order_time[ORDER];
int store,cost;
map<string,int> str2month;

void init()
{
	str2month["Jan"]=1;
	str2month["Feb"]=2;
	str2month["Mar"]=3;
	str2month["Apr"]=4;
	str2month["May"]=5;
	str2month["Jun"]=6;
	str2month["Jul"]=7;
	str2month["Aug"]=8;
	str2month["Sep"]=9;
	str2month["Oct"]=10;
	str2month["Nov"]=11;
	str2month["Dec"]=12;
}
	

int main()
{
	freopen("input.txt","r",stdin);
	init();
	char month[10];
	int day,year,hour,ask;
	while(input(query>>n) && query+n)
	{
		for(int i=0;i<query;i++)
		{
			scanf("%s%d%d%d%d",month,&day,&year,&hour,&ask);
			int mm=str2month[month];
			order_time[i]=DATE::date2hour(DATE::date(year,mm,day,hour));
			order_num[i]=ask;
			//print(order_time[i]);
		}
		input(store>>cost);
		RMQ::init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&ask);
			RMQ::mini[i][0]=(n-i)*cost+ask;
		}

		RMQ::initRMQ();
		llint ans=0;
		for(int i=0;i<query;i++)
		{
			int ll=max(1,order_time[i]-store+1);
			int rr=order_time[i];
			llint mincost=RMQ::query_min(ll,rr)-(n-order_time[i])*cost;
			ans+=mincost*order_num[i];
		}
		print(ans);
	}
	return 0;
}

