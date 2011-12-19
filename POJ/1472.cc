//Result:wizmann	1472	Accepted	768K	0MS	G++	2043B

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define SIZE 16
#define elif else if

struct command
{
	string op;
	int otime[SIZE];
	
	command(){}
	
	command(string i_op,int t,int num)
	{
		memset(otime,0,sizeof(otime));
		op=i_op;
		otime[t]=num;
	}
	
	friend command& operator +=(command &a,const command &b)
	{
		for(int i=0;i<SIZE;i++)
		{
			a.otime[i]+=b.otime[i];
		}
		return a;
	}
};

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	string temp;
	input(T);
	for(int cas=1;cas<=T;cas++)
	{
		stack<command> st;
		print("Program #"<<cas);
		printf("Runtime = ");
		input(temp);
		st.push(command(temp,0,0));
		while(st.size()>1 || st.top().op=="BEGIN")
		{
			input(temp);
			if(temp=="OP")
			{
				int num;
				input(num);
				st.push(command("OP",0,num));
			}
			elif(temp=="LOOP")
			{
				input(temp);
				if(temp=="n") st.push(command("LOOP",1,1));
				else st.push(command("LOOP",0,atoi(temp.c_str())));
			}
			elif(temp=="END")
			{
				command newst("OP",0,0);
				command stt;
				while(1)
				{
					stt=st.top();
					st.pop();
					if(stt.op=="LOOP" ||stt.op=="BEGIN") break;
					newst+=stt;
				}
				int ttime[SIZE]={0};
				if(stt.op=="LOOP")
				{
					for(int i=0;i<SIZE;i++)
					{
						for(int j=0;j<SIZE;j++)
						{
							ttime[i+j]+=newst.otime[i]*stt.otime[j];
						}
					}
					for(int i=0;i<SIZE;i++) newst.otime[i]=ttime[i];
				}
				st.push(newst);
			}
		}
		if(st.empty()) print(0);
		else
		{
			command t=st.top();
			bool flag=false;
			for(int i=SIZE-1;i>=0;i--)
			{
				if(t.otime[i])
				{
					if(flag) printf("+");
					if(i!=0 && t.otime[i]>1) printf("%d*",t.otime[i]);
					if(i>1) printf("n^%d",i);
					elif(i==1) printf("n");
					else printf("%d",t.otime[i]);
					flag=true;
				}
			}
			if(!flag) printf("0");
		}
		print("\n");
	}
	return 0;
}

