//Result:wizmann	1008	Accepted	780K	16MS	G++	1275B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

string Haab_Month[20]=
{
	"NULL",
	"pop", "no", "zip", 
	"zotz", "tzec", "xul",
	"yoxkin", "mol", "chen",
	"yax", "zac", "ceh", "mac", 
	"kankin", "muan", "pax", "koyab", "cumhu","uayet"
};

string Tzolkin_Day[20]=
{
	"imix","ik","akbal","kan","chicchan",
	"cimi","manik","lamat","muluk","ok",
	"chuen","eb","ben","ix","mem",
	"cib","caban","eznab","canac","ahau"
};

map<string,int> Haab_Month_Map;

void init()
{
	for(int i=0;i<=19;i++) Haab_Month_Map[Haab_Month[i]]=i;
}

long long getDays(int day,char *month,int year)
{
	long long res=0;
	res+=day;
	res+=365*year;
	res+=(Haab_Month_Map[month]-1)*20;
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	init();
	int T;
	int day,year;
	char month[10];
	input(T);
	print(T);
	while(T--)
	{
		scanf("%d.%s%d",&day,month,&year);
		long long total_days=getDays(day,month,year);
		//print(total_days);
		printf("%lld ",(total_days%260)%13+1);
		printf("%s ",Tzolkin_Day[(total_days%260)%20].c_str());
		printf("%lld",(total_days)/260);
		puts("");
	}
	return 0;
}
		
		
