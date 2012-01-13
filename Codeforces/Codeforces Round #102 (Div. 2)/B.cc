#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

int main()
{
    bool minus=false;
    stack<char> st;
    char inStr[512],*p=inStr;
    string digit="";
    input(inStr);
    if(*inStr=='-')
    {
        minus=true;
        p++;
    }
    
    bool zero=true;
    for(int i=0;inStr[i];i++)
    {
        if(inStr[i]>='1' && inStr[i]<='9')
        {
            zero=false;
            break;
        }
    }
    
    
    while(*p!='.' && *p) st.push(*p++);
    for(int i=0;!st.empty();i++)
    {
        if(i&&i%3==0 ) digit=','+digit;
        digit=st.top()+digit;
        st.pop();
    }
    digit+='.';
    for(int i=0;i<2;i++)
    {
        if(*p=='.') p++;
        if(*p) digit+=*p++;
        else digit+='0';
    }
    digit+='\0';
    
    if(minus && !zero)
    {
        printf("($%s)\n",digit.c_str());
    }
    else printf("$%s\n",digit.c_str());
    return 0;
}
       
    
    
