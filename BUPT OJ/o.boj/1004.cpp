#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int *a=new int[n];
    int *b=new int[n];
    int *c=new int[n];
    
    while(scanf("%d",&n)!=-1)
    {
	    memset(a,0,sizeof(int)*n);
	    memset(b,0,sizeof(int)*n);
	    memset(c,0,sizeof(int)*n);
	    for(int i=0;i<n;i++)
	    {
	            scanf("%d",&a[i]);
	    }
	    
	    for(int i=n-1;i>=0;i--)
	    {
	            int max=0;
	            for(int k=i;k<n;k++)
	            {
	                    if(a[k]<a[i])
	                    {
	                                if(b[k]>max) max=b[k];
	                    }
	            }
	            if(max==0) b[i]=1;
	            else b[i]=max+1;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	    		int min=0;
	            for(int k=i-1;k>=0;k--)
	            {
	                    if(a[k]<a[i])
	                    {
	                                if(c[k]>min) min=c[k];
	                    }
	            }
	            if(min==0) c[i]=1;
	            else c[i]=min+1;
	    }
	    
	//	  printf("B:");
	//    for(int i=0;i<n;i++)
	//    {
	//            printf("%d ",b[i]);
	//    }
	//  
	//    printf("\n");
	//    printf("C:");
	//    for(int i=0;i<n;i++)
	//    {
	//            printf("%d ",c[i]);
	//    }
	//    printf("\n");
	    
	    int max=-1;
	    int nr;
	    for(int i=0;i<n;i++)
	    {
	    	if(b[i]+c[i]>max)
	    	{
		    	max=b[i]+c[i];
		    	nr=i;
		    }
	    }
	    printf("%d\n",n-max+1);
    }
    
    return 0;
}
    
