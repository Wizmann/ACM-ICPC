#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct number
{
    int len;
    char num[110];
    bool flag;
    
    number()
    {
        len=0;
        memset(num,0,sizeof(num));
        flag=true;
    }
    
    number operator = (const char* right)
    {
        if(*right=='-')
        {
            flag=false;
            right++;
        }
        len=strlen(right);
        for(int i=0;i<len;i++)
        {
            num[i]=right[len-i-1]-'0';
        }
        
        return *this;
    }
    
    number* operator + (const number& right)
    {
        number *res;
        if(flag==right.flag)
        {
            res=plus(right);
            res->flag=flag;
        }
        else
        {
            if(compare(*this,right)==1)
            {
                res=minus(*this,right);
                res->flag=flag;
            }
            else
            {
                res=minus(right,*this);
                res->flag = right.flag;
            }
        }
        return res;
    }
    
    number* operator - (const number& right)
    {
        number *res;
        if(flag!=right.flag)
        {
            res=plus(right);
            res->flag=flag;
        }
        else
        {
            if(compare(*this,right)==1)
            {
                res=minus(*this,right);
                res->flag=this->flag;
            }
            else
            {
                res=minus(right,*this);
                res->flag=!right.flag;
            }
        }
        return res;
    }
        
    void print()
    {
        if (flag==false)
        printf("-");
        
        for(int i=0;i<len;i++)
        {
            printf("%d",num[len-i-1]);
        }
        printf("\n");
    }
    
    
    int max(number a,number b)
    {
        return a.len>b.len?a.len:b.len;
    }
    
    int compare(number a,number b)
    {
        int length=max(a,b);
        for(int i=0;i<=length;i++)
        {
            if(a.num[length-i]>b.num[length-i]) return 1;
            else if(a.num[length-i]<b.num[length-i]) return -1;
        }
        return 1;
    }
    
    number* plus(number right)
    {
        number *ret;
        ret=new number;
        int length=max(*this,right);
        int g=0;
        for(int i=0;i<length+1;i++)
        {
            ret->num[i]=(num[i]+right.num[i]+g)%10;
            g=(num[i]+right.num[i]+g)/10;
        }
        if(ret->num[length]==0) ret->len=length;
        else ret->len=length+1;
        
        return ret;
    }
    
    number* minus(number a,number b)
    {
        number *ret;
        ret=new number;
        int length=max(a,b);
        int g=0;
        for(int i=0;i<length+1;i++)
        {
            int m=a.num[i]-b.num[i]-g;
            if(m<0)
            {
                g=1;
                ret->num[i]=m+10;
            }
            else
            {
                ret->num[i]=m;
                g=0;
            }
        }
        for(int i=length;i>=0;i--)
        {
            if(ret->num[i-1]!=0)
            {
                ret->len=i;
                break;
            }
        }
        if(ret->len==0) ret->len=1;
        return ret;
    }
    
}number;


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    number *result;
    number a,b;
    char temp[110];
    scanf("%s",temp);
    a=temp;
    scanf("%s",temp);
    b=temp;
    result=a-b;
    result->print();
    return 0;
} 
