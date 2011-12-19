#include <cstdio>
#include <set>

using namespace std;

int array[200000];

int main()
{
    int t;
    scanf("%d",&t);
    set<int> box;
    set<int>::iterator iter;
    while(t--)
    {
        box.clear();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&array[i]);
        
        int i=0;
        box.insert(array[i]);
        int pop=0;
        int max=-1;
        int num=1;
        for(i=1;i<n;i++)
        {
            iter=box.find(array[i]);
            if(iter!=box.end())
            {
                if(num>max) max=num;
                iter=box.find(array[pop]);
                box.erase(iter);
                pop++;
                num--;
                i--;
            }
            else
            {
                num++;
                box.insert(array[i]);
            }
        }
        if(num>max) max=num;
        printf("%d\n",max);        
    }
    return 0;
}
