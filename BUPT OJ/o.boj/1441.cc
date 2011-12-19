//Result:1441 	Accepted	11MS	1576K	G++	2500B	
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <map>
#include <string>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x
#define elif else if

map<char,int> priTable;
char expString[100000];

void init()
{
    priTable['+']=priTable['-']=1;
    priTable['*']=priTable['/']=2;
    priTable['^']=3;
    priTable['(']=10;
    priTable[')']=-1;
}

double cal(double a,char opt,double b)
{
    if(opt=='+') return a+b;
    elif(opt=='-') return a-b;
    elif(opt=='*') return a*b;
    elif(opt=='/') return a/b;
    elif(opt=='^') return pow(a,b);
    else return -1;
}

int main()
{
    init();
    
    int cas;
    input(cas);
    while(cas--)
    {
        stack<double> opnd;
        stack<char> optr;
        memset(expString,0,sizeof(expString));
        scanf("%s",expString);
        char *p=expString;
        while(*p)
        {
            if(isdigit(*p))
            {
                double val;
                int k;
                sscanf(p,"%lf%n",&val,&k);
                opnd.push(val);
                p+=k;
            }
            else
            {
                if(optr.empty()) optr.push(*p);
                else
                {
                    while(optr.top()!='(' && ( priTable[*p] <= priTable[optr.top()] ) )
                    {
                        char ch=optr.top();
                        double b=opnd.top();
                        opnd.pop();
                        double a=opnd.top();
                        opnd.pop();
                        double mv=cal(a,ch,b);
                        optr.pop();
                        opnd.push(mv);
                        if(optr.empty()) break;
                    }
                    if(*p!=')') optr.push(*p);
                    else 
                    {
                        if(!optr.empty()) optr.pop();
                    }
                }
                p++;       
            }
        }
        while (!optr.empty())
        {
            double b=opnd.top();
            opnd.pop();
            double a=opnd.top();
            opnd.pop();
            double mv=cal(a,optr.top(),b);
            optr.pop();
            opnd.push(mv);
        }
        printf("%.lf\n",opnd.top()+1e-4);
    }
    return 0;
}
        

