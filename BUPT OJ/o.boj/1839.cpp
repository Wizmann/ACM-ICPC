#include <stdio.h>
main(){int a,b;while(scanf("%d,%d",&a,&b)==2)printf("%d\n",a-b>0?a-b:b-a);}