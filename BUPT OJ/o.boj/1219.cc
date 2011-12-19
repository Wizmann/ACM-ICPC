#include <cstdio>
#include <cstdlib>
int cmp(const void *a,const void *b){return *(int*)b-*(int*)a;}
int array[20010];
int main(){int t,n;scanf("%d",&t);while(t--){int sum=0;scanf("%d",&n);for(int i=0;i<n;i++) scanf("%d",&array[i]);qsort(array,n,sizeof(int),cmp);for(int i=2;i<n;i+=3) sum+=array[i];printf("%d\n",sum);}return 0;}
		
