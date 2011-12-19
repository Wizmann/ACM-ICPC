#include <stdio.h> 
#include <stdlib.h> 
 
int main()
{ 
    char str[6]; 
    int res=0;
    for(int i=0;i<4;i++)
    { 
        gets(str);          
        for(int j=0;j<4;j++)
        { 
            switch (str[j])
        { 
                case 'A':res+=abs(i-0)+abs(j-0);break; 
                case 'B':res+=abs(i-0)+abs(j-1);break; 
                case 'C':res+=abs(i-0)+abs(j-2);break; 
                case 'D':res+=abs(i-0)+abs(j-3);break; 
                case 'E':res+=abs(i-1)+abs(j-0);break; 
                case 'F':res+=abs(i-1)+abs(j-1);break; 
                case 'G':res+=abs(i-1)+abs(j-2);break; 
                case 'H':res+=abs(i-1)+abs(j-3);break; 
                case 'I':res+=abs(i-2)+abs(j-0);break; 
                case 'J':res+=abs(i-2)+abs(j-1);break; 
                case 'K':res+=abs(i-2)+abs(j-2);break; 
                case 'L':res+=abs(i-2)+abs(j-3);break; 
                case 'M':res+=abs(i-3)+abs(j-0);break; 
                case 'N':res+=abs(i-3)+abs(j-1);break; 
                case 'O':res+=abs(i-3)+abs(j-2);break; 
            } 
        } 
    } 
    printf("%d\n",res); 
    return 0; 
} 


