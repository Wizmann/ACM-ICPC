#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;
int n;
int array[50010];
int grade[50010];

int cmi()
{
    set<int> st;
    set<int>::iterator iter;
    st.insert(grade[1]);
    for(int i=2;i<=n;i++)
    {
        iter=st.lower_bound(grade[i]);
        if(iter==st.end()) st.insert(grade[i]);
        else
        {
            st.erase(iter);
            st.insert(grade[i]);
        }
    }
    return st.size();
}


int main()
{

    int t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&array[i]);
    }

    
    while(scanf("%d",&t)!=EOF)
    {
        memset(grade,0,sizeof(grade));
        grade[t]=array[1];
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&t);
            grade[t]=array[i];
        }
        
        printf("%d\n",cmi());
    }
    return 0;
}
