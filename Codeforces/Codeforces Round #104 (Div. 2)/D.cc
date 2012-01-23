//Result:Wizmann	 D - Lucky Number 2	 GNU C++	Accepted	 80 ms
//算法：贪心
//
//先建立以"4747..."为骨架的串
//然后补位，将47串和74串生成完
//再插入4和7，形成最小串。。。
//
//贪心思想很重要，可惜我没有啊。。。 － －。。。
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define input(x) cin>>x
#define print(x) cout<<x<<endl

int v,s,vs,sv;
void printAns()
{
	print("vier: "<<v<<" sieben: "<<s<<" vs: "<<vs<<" sv: "<<sv);
}

int main()
{
	freopen("d.txt","r",stdin);
	
	//vier,sieben,vier-sieben,sieben-vier
	input(v>>s>>vs>>sv);
	string ans="";
	bool flag=true;
	if(v<vs || s<vs || v<sv || v<sv) flag=false;
	else
	{
		for(int i=0;i<vs;i++) ans+="47";
		v-=vs;
		s-=vs;
		sv-=(vs-1);
		if(sv>2 || sv<0) flag=false;
		else
		{
			if(sv==1 || sv==2)
			{
				if(v&&sv)
				{
					ans+="4";
					v--;sv--;
				}
				if(s&&sv)
				{
					ans="7"+ans;
					s--;sv--;
				}
			}
			if(s<0 || v<0 || sv!=0) flag=false;
			else
			{
				if(ans.empty())
				{
					if(s&&v) flag=false;
					else if(v) ans.insert(0,v,'4');
					else if(s) ans.insert(0,s,'7');
				}
				else
				{
					for(int i=0;i<(int)ans.length();i++)
					{
						if(!v && !s) break;
						else if(ans[i]=='4' && v)
						{
							ans.insert(i,v,'4');
							v=0;
						}
					}
					for(int i=ans.length()-1;i>=0;i--)
					{
						if(!v && !s) break;
						else if(ans[i]=='7' && s)
						{
							ans.insert(i,s,'7');
							s=0;
						}
					}
				}
			}
		}
	}
	
	if(flag) print(ans);
	else print(-1);
	
	return 0;
}
