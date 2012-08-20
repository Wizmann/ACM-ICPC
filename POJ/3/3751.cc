//Result:wizmann	3751	Accepted	756K	0MS	G++	907B
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	input(T);
	string instr;
	string info[10];
	int ind;
	while(T--)
	{
		ind=0;
		string tmpstr;
		input(instr);
		instr+='#';
		for(int i=0;i<(int)instr.length();i++)
		{
			if(instr[i]>='0' && instr[i]<='9')
			{
				tmpstr+=instr[i];
			}
			else
			{
				info[ind++]=tmpstr;
				tmpstr="";
			}
		}
		int hour=atoi(info[3].c_str());
		if(hour>=12)
		{
			if(hour>12) hour-=12;
			info[6]="pm";
		}
		else
		{
			if(hour==0) hour+=12;
			info[6]="am";
		}
		char tmp[12];
		sprintf(tmp,"%02d",hour);
		info[3]=tmp;
		print(info[1]<<'/'<<info[2]<<'/'<<info[0]<<'-'<<
				info[3]<<':'<<info[4]<<':'<<info[5]<<info[6]);
	}
	return 0;
}


